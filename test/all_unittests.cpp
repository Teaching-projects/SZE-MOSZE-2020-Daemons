#include "../JSON.h"
#include "../Hero.h"
#include "../Monster.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

TEST(all_unitsTest,hero_load_test)
{
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    ASSERT_TRUE(hero.getHealthPoints() == 30);
    ASSERT_TRUE(hero.getName() == "Prince Aidan of Khanduras");
    ASSERT_TRUE(hero.getDamage() == 3);
    ASSERT_TRUE(hero.getAttackCoolDown() == 1.1);
}
TEST(all_unitsTest,Monster_load_test)
{
    Monster monster{Monster::parse("../Zombie.json")};
    ASSERT_TRUE(monster.getHealthPoints() == 10);
    ASSERT_TRUE(monster.getName() == "Zombie");
    ASSERT_TRUE(monster.getDamage() == 1);
    ASSERT_TRUE(monster.getAttackCoolDown() == 2.8);
}
TEST(all_unitsTest,Unit_edge_case_file)
{
    JSON scenario = JSON::parseFromFile("../scenario1.json");
    ASSERT_TRUE(scenario.count("hero") == true);
    ASSERT_TRUE(scenario.count("monsters") == true);
    std::string hero_name = scenario.get<std::string>("hero");
    ASSERT_TRUE(hero_name == "Dark_Wanderer.json");
}
TEST(all_unitsTest,typetest)
{
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    EXPECT_EQ(typeid(int),typeid(hero.getHealthPoints()));
    EXPECT_EQ(typeid(std::string),typeid(hero.getName()));
    EXPECT_EQ(typeid(double),typeid(hero.getAttackCoolDown()));
    EXPECT_EQ(typeid(int),typeid(hero.getDamage()));
    
}
TEST(all_unitsTest,Unit_fight)
{
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    Monster monster{Monster::parse("../Zombie.json")};
    hero.fightTilDeath(monster);
    ASSERT_TRUE(monster.getHealthPoints() < hero.getHealthPoints());
}
TEST(all_unitsTest,Generate_hero)
{
    Hero hero(30,10,"Hero_of_the_heroes",1.202,2,5,1,0.011);
    Monster monster(30,10,"Enemy",0.02);
    ASSERT_EQ(hero.getName(),"Hero_of_the_heroes");
    ASSERT_EQ(hero.getHealthPoints(),30);
    ASSERT_EQ(hero.getDamage(),10);
    ASSERT_EQ(hero.getAttackCoolDown(),1.202);

    ASSERT_EQ(monster.getName(),"Enemy");
    ASSERT_EQ(monster.getHealthPoints(),30);
    ASSERT_EQ(monster.getDamage(),10);
    ASSERT_EQ(monster.getAttackCoolDown(),0.02);

}
TEST(all_unitsTest,no_throw_check)
{
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    Monster monster{Monster::parse("../Zombie.json")};
    EXPECT_NO_THROW(hero.fightTilDeath(monster));
}
TEST(all_unitsTest,missing_keys)
{
    EXPECT_NO_THROW(Hero::parse("../Dark_Wanderer.json"));
}
TEST(all_unitsTest,messed_up_keys)
{
    Monster unit_messedup{Monster::parse("messedup_keys.json")};
    ASSERT_TRUE(unit_messedup.getName() == "Kakarott");
    ASSERT_EQ(unit_messedup.getHealthPoints(),120);
    ASSERT_EQ(unit_messedup.getDamage(),25);
    ASSERT_DOUBLE_EQ(unit_messedup.getAttackCoolDown(),10.0);
}
TEST(all_unitsTest,no_throw_fromUnitparser)
{
    EXPECT_NO_THROW(Hero::parse("../Dark_Wanderer.json"));
    EXPECT_NO_THROW(Monster::parse("../Fallen.json"));
    EXPECT_NO_THROW(Monster::parse("../Zombie.json"));
}
TEST(all_unitsTest,Monster_wins)
{
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    Monster monster{Monster::parse("../Zombie.json")};
    hero.fightTilDeath(monster);
    ASSERT_TRUE(hero.getHealthPoints() < monster.getHealthPoints());
}
TEST(all_unitsTest,test_levelup_logic)
{
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    hero.levelUp();
    ASSERT_TRUE(hero.getLevel() == 2);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}