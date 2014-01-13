/*
 * Copyright (c) 2013 Mark Travis <mtravis15432+src@gmail.com>
 * All rights reserved. No warranty, explicit or implicit, provided.
 *
 * This file is part of InfiniSQL(tm).
 
 * InfiniSQL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * InfiniSQL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with InfiniSQL. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file   Serdes.cc
 * @author Mark Travis <mtravis15432+src@gmail.com>
 * @date   Tue Jan  7 17:16:03 2014
 * 
 * @brief  serialization and deserialization for POD and generic data types
 */

#include "Serdes.h"
#line 30 "Serdes.cc"

Serdes::Serdes() : isreadonly (false), pos (0), val ({0, NULL})
{
    
}

Serdes::Serdes(size_t mv_sizearg) : isreadonly (false), pos (0)
{
    val.mv_data=new (std::nothrow) char[mv_sizearg];
    if (val.mv_data != NULL)
    {
        val.mv_size=mv_sizearg;
    }
    else
    {
        val.mv_size=0;
    }
}

Serdes::Serdes(MDB_val &valarg) : isreadonly (true), pos (0), val (valarg)
{
    
}

Serdes::~Serdes()
{
    if (isreadonly==false)
    {
        delete (char *)val.mv_data;
    }
}

void Serdes::ser(int16_t d)
{
    memcpy(val.mv_data, &d, sizeof(d));
    pos+=sersize(d);
}

size_t Serdes::sersize(int16_t d)
{
    return sizeof(d);
}

void Serdes::des(int16_t *d)
{
    memcpy(d, val.mv_data, sizeof(*d));
    pos+=sersize(*d);
}

void Serdes::ser(int32_t d)
{
    memcpy(val.mv_data, &d, sizeof(d));
    pos+=sersize(d);
}

size_t Serdes::sersize(int32_t d)
{
    return sizeof(d);
}

void Serdes::des(int32_t *d)
{
    memcpy(d, val.mv_data, sizeof(*d));
    pos+=sersize(*d);
}

void Serdes::ser(int64_t d)
{
    memcpy(val.mv_data, &d, sizeof(d));
    pos+=sersize(d);
}

size_t Serdes::sersize(int64_t d)
{
    return sizeof(d);
}

void Serdes::des(int64_t *d)
{
    memcpy(d, val.mv_data, sizeof(*d));
    pos+=sersize(*d);
}

void Serdes::ser(char d)
{
    memcpy(val.mv_data, &d, sizeof(d));
    pos+=sersize(d);
}

size_t Serdes::sersize(char d)
{
    return sizeof(d);
}

void Serdes::des(char *d)
{
    memcpy(d, val.mv_data, sizeof(*d));
    pos+=sersize(*d);
}

void Serdes::ser(bool d)
{
    memcpy(val.mv_data, &d, sizeof(d));
    pos+=sersize(d);
}

size_t Serdes::sersize(bool d)
{
    return sizeof(d);
}

void Serdes::des(bool *d)
{
    memcpy(d, val.mv_data, sizeof(*d));
    pos+=sersize(*d);
}

void Serdes::ser(std::string &d)
{
    size_t s=d.size();
    ser((int64_t)s);
    d.copy((char *)val.mv_data, s, 0);
    pos+=s;
}

size_t Serdes::sersize(std::string &d)
{
    return sizeof(int64_t)+d.size();
}

void Serdes::des(std::string &d)
{
    int64_t s;
    des(&s);
    d.assign((char *)val.mv_data, s);
    pos+=s;
}

void Serdes::ser(void *d, size_t dsize)
{
    memcpy(val.mv_data, d, dsize);
}

void Serdes::des(void *d, size_t dsize)
{
    memcpy(d, val.mv_data, dsize);
    pos+=dsize;
}

void Serdes::rewind()
{
    pos=0;
}

void Serdes::ffwd()
{
    pos=val.mv_size-1;
}

bool Serdes::isbegin()
{
    return pos==0 ? true : false;
}

bool Serdes::isend()
{
    return pos==val.mv_size-1 ? true : false;
}
