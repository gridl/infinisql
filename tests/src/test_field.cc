
#include <gtest/gtest.h>
#include "Catalog.h"
#include "Schema.h"
#include "Table.h"
#include "Field.h"

const size_t serdes_test_buffer_size = 1024;


TEST(FieldTest, SetType_tinyint) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_TINYINT};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int8_t rv1, rv2;
	int8_t miv { std::numeric_limits<int8_t>::min() };
	int8_t mav { std::numeric_limits<int8_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}


TEST(FieldTest, SetType_smallint) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_SMALLINT};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int8_t rv1, rv2;
	int8_t miv { std::numeric_limits<int8_t>::min() };
	int8_t mav { std::numeric_limits<int8_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int16_t rv1, rv2;
	int16_t miv { std::numeric_limits<int16_t>::min() };
	int16_t mav { std::numeric_limits<int16_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}


TEST(FieldTest, SetType_int) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_INT};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int8_t rv1, rv2;
	int8_t miv { std::numeric_limits<int8_t>::min() };
	int8_t mav { std::numeric_limits<int8_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int16_t rv1, rv2;
	int16_t miv { std::numeric_limits<int16_t>::min() };
	int16_t mav { std::numeric_limits<int16_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int32_t rv1, rv2;
	int32_t miv { std::numeric_limits<int32_t>::min() };
	int32_t mav { std::numeric_limits<int32_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}


TEST(FieldTest, SetType_bigint) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_BIGINT};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int8_t rv1, rv2;
	int8_t miv { std::numeric_limits<int8_t>::min() };
	int8_t mav { std::numeric_limits<int8_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int16_t rv1, rv2;
	int16_t miv { std::numeric_limits<int16_t>::min() };
	int16_t mav { std::numeric_limits<int16_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int32_t rv1, rv2;
	int32_t miv { std::numeric_limits<int32_t>::min() };
	int32_t mav { std::numeric_limits<int32_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	int64_t rv1, rv2;
	int64_t miv { std::numeric_limits<int64_t>::min() };
	int64_t mav { std::numeric_limits<int64_t>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}


TEST(FieldTest, SetType_boolean) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_BOOLEAN};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	bool rv1, rv2;
	bool miv { std::numeric_limits<bool>::min() };
	bool mav { std::numeric_limits<bool>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}


TEST(FieldTest, SetType_real) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_REAL};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	float rv1, rv2;
	float miv { std::numeric_limits<float>::min() };
	float mav { std::numeric_limits<float>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}


TEST(FieldTest, SetType_double_precision) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_DOUBLE_PRECISION};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	float rv1, rv2;
	float miv { std::numeric_limits<float>::min() };
	float mav { std::numeric_limits<float>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	double rv1, rv2;
	double miv { std::numeric_limits<double>::min() };
	double mav { std::numeric_limits<double>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}


TEST(FieldTest, SetType_float) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_FLOAT};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	float rv1, rv2;
	float miv { std::numeric_limits<float>::min() };
	float mav { std::numeric_limits<float>::max() };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}


TEST(FieldTest, SetType_numeric) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_NUMERIC, 128};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<int8_t>::min()) };
	std::string mav { std::to_string(std::numeric_limits<int8_t>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<int16_t>::min()) };
	std::string mav { std::to_string(std::numeric_limits<int16_t>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<int32_t>::min()) };
	std::string mav { std::to_string(std::numeric_limits<int32_t>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<int64_t>::min()) };
	std::string mav { std::to_string(std::numeric_limits<int64_t>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}


TEST(FieldTest, SetType_decimal) {
    auto c = std::make_shared<Catalog>(0, "test_catalog");
    auto s = std::make_shared<Schema>(c, "test_schema");
    auto t = std::make_shared<Table>(s, "test_table");
    Field f{t, "test_field", Field::type_e::TYPE_DECIMAL, 128};
    
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<int8_t>::min()) };
	std::string mav { std::to_string(std::numeric_limits<int8_t>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<int16_t>::min()) };
	std::string mav { std::to_string(std::numeric_limits<int16_t>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<int32_t>::min()) };
	std::string mav { std::to_string(std::numeric_limits<int32_t>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<int64_t>::min()) };
	std::string mav { std::to_string(std::numeric_limits<int64_t>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<float>::min()) };
	std::string mav { std::to_string(std::numeric_limits<float>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}
	{
	Serdes sd1{serdes_test_buffer_size}, sd2{serdes_test_buffer_size};
	FieldValue fv, tv1, tv2;
	bool is_null { false };
	std::string rv1, rv2;
	std::string miv { std::to_string(std::numeric_limits<double>::min()) };
	std::string mav { std::to_string(std::numeric_limits<double>::max()) };
	fv.set(miv);
	f.serValue(fv, sd1);
	f.desValue(sd1, tv1);
	tv1.get(rv1, is_null);
	EXPECT_EQ(miv, rv1);
	EXPECT_FALSE(is_null);
	fv.set(mav);
	f.serValue(fv, sd2);
	f.desValue(sd2, tv2);
	tv2.get(rv2, is_null);
	EXPECT_EQ(mav, rv2);
	EXPECT_FALSE(is_null);
	}

}

