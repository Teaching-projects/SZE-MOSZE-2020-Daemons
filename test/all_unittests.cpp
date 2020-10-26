#include "../JsonParser.h"
#include "../Control.h"
#include "../Unit.h"
#include <gtest/gtest.h>
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <stdio.h>


TEST(all_unitsTest,jsonPars_test)
{
    std::map<std::string, std::string> remap = JsonParser::parseJSON("units/unit1.json");
    ASSERT_TRUE(std::stod(remap["hp"]) == 120);
    ASSERT_TRUE(remap["name"] == "Kakarott");
    ASSERT_TRUE(std::stod(remap["dmg"]) == 25);
    ASSERT_TRUE(std::stod(remap["attackcooldown"]) == 10);
}
TEST(all_unitsTest,Unit_parser_get)
{
    Unit unit_one = Unit::parseUnit("units/unit1.json");
    ASSERT_TRUE(unit_one.getName() == "Kakarott");
    ASSERT_EQ(unit_one.getHp(),120);
    ASSERT_EQ(unit_one.getDmg(),25);
    ASSERT_DOUBLE_EQ(unit_one.getAs(),10.0);
}
TEST(all_unitsTest,Unit_edge_case_file)
{
    std::map<std::string, std::string> remap = JsonParser::parseJSON("edge_case.json");
    ASSERT_TRUE(std::stod(remap["hp"]) == 120);
    ASSERT_TRUE(remap["name"] == "Kakarott");
    ASSERT_TRUE(std::stod(remap["dmg"]) == 25);
    ASSERT_TRUE(std::stod(remap["attackcooldown"]) == 10);
}
TEST(all_unitsTest,typetest)
{
    Unit unit_o(100,30,"Wukkie",20);
    EXPECT_EQ(typeid(int),typeid(unit_o.getHp()));
    EXPECT_EQ(typeid(int),typeid(unit_o.getDmg()));
    EXPECT_EQ(typeid(std::string),typeid(unit_o.getName()));
    EXPECT_EQ(typeid(double),typeid(unit_o.getAs()));
}
TEST(all_unitsTest,Unit_fight)
{
    Unit unit_one = Unit::parseUnit("units/unit1.json");
    Unit unit_two = Unit::parseUnit("units/unit2.json");
    unit_one.Fight(&unit_two);
    ASSERT_TRUE(unit_one.getHp() == 0 || unit_two.getHp() == 0);
}
TEST(all_unitsTest,Unit_boost)
{
    Unit unit_one = Unit::parseUnit("units/unit1.json");
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}