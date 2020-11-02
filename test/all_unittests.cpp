#include "../JSON.h"
#include "../Hero.h"
#include "../Monster.h"
#include <gtest/gtest.h>
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <stdio.h>


TEST(all_unitsTest,jsonPars_test)
{
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    ASSERT_TRUE(hero.getHealthPoints() == 30);
    ASSERT_TRUE(hero.getName() == "Prince Aidan of Khanduras");
    ASSERT_TRUE(hero.getDamage() == 3);
    ASSERT_TRUE(hero.getAttackCoolDown() == 1.1);
}
// TEST(all_unitsTest,Unit_parser_get)
// {
//     Unit unit_one = Unit::parseUnit("units/unit1.json");
//     ASSERT_TRUE(unit_one.getName() == "Kakarott");
//     ASSERT_EQ(unit_one.getHp(),120);
//     ASSERT_EQ(unit_one.getDmg(),25);
//     ASSERT_DOUBLE_EQ(unit_one.getAs(),10.0);
// }
// TEST(all_unitsTest,Unit_edge_case_file)
// {
//     std::map<std::string, std::string> remap = JSON::parseJSON("edge_case.json");
//     ASSERT_TRUE(std::stod(remap["hp"]) == 120);
//     ASSERT_TRUE(remap["name"] == "Kakarott");
//     ASSERT_TRUE(std::stod(remap["dmg"]) == 25);
//     ASSERT_TRUE(std::stod(remap["attackcooldown"]) == 10);
// }
// TEST(all_unitsTest,typetest)
// {
//     Unit unit_o(100,30,"Wukkie",20);
//     EXPECT_EQ(typeid(int),typeid(unit_o.getHp()));
//     EXPECT_EQ(typeid(int),typeid(unit_o.getDmg()));
//     EXPECT_EQ(typeid(std::string),typeid(unit_o.getName()));
//     EXPECT_EQ(typeid(double),typeid(unit_o.getAs()));
// }
// TEST(all_unitsTest,Unit_fight)
// {
//     Unit unit_one = Unit::parseUnit("units/unit1.json");
//     Unit unit_two = Unit::parseUnit("units/unit2.json");
//     unit_one.Fight(&unit_two);
//     ASSERT_TRUE(unit_one.getHp() == 0 || unit_two.getHp() == 0);
// }
// TEST(all_unitsTest,Unit_stats)
// {
//     Unit unit_one = Unit::parseUnit("units/unit1.json");
//     Unit unit_two = Unit::parseUnit("units/unit2.json");
//     unit_one.Fight(&unit_two);
//     ASSERT_TRUE(unit_one.getHp() >= unit_two.getHp() || unit_one.getHp() < unit_two.getHp());
//     if(unit_one.getHp() < unit_two.getHp()) ASSERT_TRUE(unit_two.getDmg() > unit_one.getDmg());
//     else ASSERT_TRUE(unit_two.getDmg() > unit_one.getDmg());
// }
// TEST(all_unitsTest,no_throw_check)
// {
//     Unit unit_o(100,30,"Wukkie",20);
//     Unit unit_t(100,30,"Wukkie",20);
//     EXPECT_NO_THROW(unit_o.Fight(&unit_t));
// }
// TEST(all_unitsTest,missing_keys)
// {
//     ASSERT_THROW(JSON::parseJSON("missing_keys.json"),std::runtime_error);
// }
// TEST(all_unitsTest,messed_up_keys)
// {
//     Unit unit_messedup = Unit::parseUnit("messedup_keys.json");
//     ASSERT_TRUE(unit_messedup.getName() == "Kakarott");
//     ASSERT_EQ(unit_messedup.getHp(),120);
//     ASSERT_EQ(unit_messedup.getDmg(),25);
//     ASSERT_DOUBLE_EQ(unit_messedup.getAs(),10.0);
// }
// TEST(all_unitsTest,no_throw_fromUnitparser)
// {
//     EXPECT_NO_THROW(Unit::parseUnit("units/unit1.json"));
//     EXPECT_NO_THROW(Unit::parseUnit("units/unit2.json"));
//     EXPECT_NO_THROW(Unit::parseUnit("units/unit3.json"));
// }
// TEST(all_unitsTest,gameplay_logic)
// {
//     Unit unit_o(100,30,"Wukkie",20);
//     Unit unit_t(1000,300,"Big Wukkie",200);
//     unit_o.Fight(&unit_t);
//     ASSERT_TRUE(unit_o.getHp() == 0);
//     ASSERT_TRUE(unit_o.getHp() < unit_t.getHp());
//     ASSERT_TRUE(unit_o.getDmg() < unit_t.getDmg());
// }
// TEST(all_unitsTest,test_levelup_logic)
// {
//     Unit unit_one = Unit::parseUnit("units/unit2.json");
//     Unit unit_two = Unit::parseUnit("units/unit3.json");
//     unit_one.Fight(&unit_two);
//     ASSERT_EQ(unit_two.getMaxHp(),280);
// }


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}