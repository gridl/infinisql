/*
 * Copyright (c) 2013 Mark Travis <mtravis15432+src@gmail.com>
 * All rights reserved. No warranty, explicit or implicit, provided.
 *
 * This file is part of InfiniSQL (tm). It is available either under the
 * GNU Affero Public License or under a commercial license. Contact the
 * copyright holder for information about a commercial license if terms
 * of the GNU Affero Public License do not suit you.
 *
 * This copy of InfiniSQL is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * InfiniSQL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero Public License for more details.
 *
 * You should have received a copy of the GNU Affero Public License
 * along with InfiniSQL. It should be in the top level of the source
 * directory in a file entitled "COPYING".
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include "infinisql_ObGateway.h"
#line 28 "ObGateway.cc"

ObGateway::ObGateway(Topology::partitionAddress *myIdentityArg) :
  myIdentity(*myIdentityArg)
{
  delete myIdentityArg;

  mboxes.nodeid = myIdentity.address.nodeid;
  mboxes.update(myTopology);
  updateRemoteGateways();

  // connect to listener (on local system), first instance
  int pgsockfd=0;

  if (myIdentity.instance==0)
  {
    pgsockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un pgremote;
    pgremote.sun_family = AF_UNIX;
    strncpy(pgremote.sun_path, listenerudsockfile.c_str(),
            listenerudsockfile.size());
    socklen_t remotelen = strlen(pgremote.sun_path)+sizeof(pgremote.sun_family);

    if (connect(pgsockfd, (struct sockaddr *)&pgremote, remotelen) == -1)
    {
      printf("%s %i can't connect to listenersockfile %s errno %i\n",
             __FILE__, __LINE__, listenerudsockfile.c_str(), errno);
      exit(1);
    }
  }

  int waitfor = 100;

  while (1)
  {
    for (size_t inmsg=0; inmsg < 5000; inmsg++)
    {
      class Message *msgrcv = myIdentity.mbox->receive(waitfor);

      if (msgrcv==NULL)
      {
        waitfor = 100;
        break;
      }

      waitfor = 0;

      switch (msgrcv->topic)
      {
        case TOPIC_TOPOLOGY:
          mboxes.update(myTopology);
          updateRemoteGateways();
          break;

        case TOPIC_CLOSESOCKET:
        {
          class MessageSocket *msg =
              new class MessageSocket(((class MessageSocket *)msgrcv)->socket,
                                          0, LISTENER_NONE, 0);
          send(pgsockfd, &msg, sizeof(msg), 0);
        }
        break;

        default: // destined for remote host
      {
          boost::unordered_map< int64_t,
                msgpack::packer<msgpack::sbuffer> *>::iterator it;
          it = pendingMessagesPack.find(msgrcv->destAddr.nodeid);

          if (it == pendingMessagesPack.end())
          {
            pendingMessagesPack[msgrcv->destAddr.nodeid] =
              new msgpack::packer<msgpack::sbuffer>
            (&pendingMessagesSbuf[msgrcv->destAddr.nodeid]);
          }

          msgpack::packer<msgpack::sbuffer> &packRef =
            *pendingMessagesPack[msgrcv->destAddr.nodeid];
          msgrcv->ser(packRef);
        }
      }
    }

    // send all pendings
    boost::unordered_map<int64_t, msgpack::sbuffer>::iterator it;

    for (it = pendingMessagesSbuf.begin(); it != pendingMessagesSbuf.end();
         it++)
    {
      // first,second: nodeid, sbuf
      msgpack::sbuffer &sbufRef = it->second;
      string sendstr(sizeof(size_t)+sbufRef.size(), 0);
      size_t s = sbufRef.size();
      memcpy(&sendstr[0], &s, sizeof(size_t));
      memcpy(&sendstr[sizeof(size_t)], sbufRef.data(), sbufRef.size());
      ssize_t sended = send(remoteGateways[it->first], sendstr.c_str(),
                            sendstr.size(), 0);
      ssize_t ss;
      memcpy(&ss, &sendstr[0], sizeof(ssize_t));

      if (sended == -1)
      {
        printf("%s %i send errno %i nodeid %li instance %li it->first %i socket %i\n",
               __FILE__, __LINE__, errno, myTopology.nodeid, myIdentity.instance,
               (int)it->first, remoteGateways[it->first]);
      }

      delete pendingMessagesPack[it->first];
    }

    pendingMessagesSbuf.clear();
    pendingMessagesPack.clear();
  }
}

ObGateway::~ObGateway()
{
}

void ObGateway::updateRemoteGateways()
{
  map< int64_t, vector<string> >::iterator it;

  if (!myTopology.ibGateways.empty() &&
          (int64_t)remoteGateways.size() < myTopology.ibGateways.rbegin()->first+1)
  {
    remoteGateways.resize(myTopology.ibGateways.rbegin()->first+1, 0);
  }

  for (it = myTopology.ibGateways.begin(); it != myTopology.ibGateways.end();
       it++)
  {
    vector<string> &vecstringRef = it->second;
    
    if (it->first==myTopology.nodeid)
    {
      continue;
    }
    if ((int64_t)myTopology.ibGateways[it->first].size() < myIdentity.instance+1)
    {
      continue;
    }
    
    if (remoteGateways[it->first]==0)
    {
      // connect to server
      int sockfd;
      size_t found = vecstringRef[myIdentity.instance].find(':');
      string node = vecstringRef[myIdentity.instance].substr(0, found);
      string service = vecstringRef[myIdentity.instance].substr(found+1,
              vecstringRef[myIdentity.instance].size()-(found+1));
      struct addrinfo hints;
      memset(&hints, 0, sizeof(struct addrinfo));
      hints.ai_family = AF_INET;
      hints.ai_socktype = SOCK_STREAM;
      hints.ai_flags = AI_PASSIVE;
      struct addrinfo *servinfo;

      if (getaddrinfo(node.c_str(), service.c_str(), &hints,
              &servinfo))
      {
        printf("%s %i getaddrinfo\n", __FILE__, __LINE__);
        return;
      }

      sockfd = socket(servinfo->ai_family, servinfo->ai_socktype,
              servinfo->ai_protocol);
      if (sockfd == -1)
      {
        printf("%s %i socket\n", __FILE__, __LINE__);
        return;
      }

      if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen))
      {
        printf("%s %i connect errno %i '%s:%s'\n", __FILE__, __LINE__,
                errno, node.c_str(), service.c_str());
        return;
      }

      freeaddrinfo(servinfo);

      remoteGateways[it->first] = sockfd;
    }
  }
}

// launcher, regular function
void *obGateway(void *identity)
{
  ObGateway((Topology::partitionAddress *)identity);
  return NULL;
}