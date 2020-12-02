#include "../JSON.h"
#include "../Hero.h"
#include "../Monster.h"
#include "../Map.h"
#include "../Game.h"
#include "../MarkedMap.h"
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
    ASSERT_TRUE(hero.getphysDamage() == 3);
    ASSERT_TRUE(hero.getAttackCoolDown() == 1.1);
    ASSERT_TRUE(hero.getDefense()== 2);
    ASSERT_TRUE(hero.getmagicDamage()== 2);
    ASSERT_TRUE(hero.getXP()== 0); 
}
TEST(all_unitsTest,Monster_load_test)
{
    Monster monster{Monster::parse("../Zombie.json")};
    ASSERT_TRUE(monster.getHealthPoints() == 10);
    ASSERT_TRUE(monster.getName() == "Zombie");
    ASSERT_TRUE(monster.getphysDamage() ==2);
    ASSERT_TRUE(monster.getAttackCoolDown() == 2.8);
    ASSERT_TRUE(monster.getDefense()== 2);
    ASSERT_TRUE(monster.getmagicDamage()== 2);
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
    EXPECT_EQ(typeid(int),typeid(hero.getphysDamage()));
    
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
    ASSERT_TRUE(hero.getHealthPoints() > monster.getHealthPoints());
}
TEST(all_unitsTest,test_levelup_logic)
{
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    hero.levelUp();
    ASSERT_TRUE(hero.getLevel() == 2);
}
TEST(all_unitsTest, mapClassTest){
    ASSERT_NO_THROW(Map("../map.txt"));
    ASSERT_THROW(Map("nosuchmap.txt"),std::runtime_error);
    Map test("../map.txt");
    ASSERT_THROW(test.get(2689,3543),Map::WrongIndexException);       
}
TEST(all_unitsTest, map_put_test){
    Game game{};
    Map map("../map.txt");
    ASSERT_NO_THROW(game.setMap(map));
}
TEST(all_unitsTest, heroPuTest){
    Game game{};
    Map map("../map.txt");
    game.setMap(map);
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    ASSERT_NO_THROW(game.putHero(hero,1,1));
}
TEST(all_unitsTest, light_radius_test){
    Hero hero{Hero::parse("../Dark_Wanderer.json")};
    ASSERT_TRUE(hero.getLightRadius() == 2);
    hero.levelUp();
    ASSERT_TRUE(hero.getLightRadius() == 4);
TEST(all_unitsTest, marked_map_pose_test){
    MarkedMap map("../markedmap.txt");
    std::pair<int,int> hero = map.getHeroPosition();
    ASSERT_TRUE(hero.first == 1);
    ASSERT_TRUE(hero.second == 2);

    std::vector<std::pair<int,int>> monsters = map.getMonsterPositions('2');
    std::cout << monsters[0].first << " " << monsters[0].second << "\n";
    ASSERT_TRUE(monsters[0].first == 2);
    ASSERT_TRUE(monsters[0].second == 6);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}