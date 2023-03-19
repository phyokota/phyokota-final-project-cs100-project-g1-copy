#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string.h>
#include "../Player-Class/Player.h"

using namespace std;

//testing getType
TEST(ConstructorTests, testMelee) {
    string name = "testMelee";
    Melee *aPlayer = new Melee(MELEE, name);
    EXPECT_EQ(aPlayer->get_type(), MELEE);
}

TEST(ConstructorTests, testRange) {
    string name = "testRange";
    Range *aPlayer = new Range(RANGE, name);
    EXPECT_EQ(aPlayer->get_type(), RANGE);
}

TEST(ConstructorTests, testMage) {
    string name = "testMage";
    Mage *aPlayer = new Mage(MAGE, name);
    EXPECT_EQ(aPlayer->get_type(), MAGE);
}

//testing getHealth default & after damaging
TEST(HealthTests, defaultHealth) {
    string name = "testMelee";
    Melee *aPlayer = new Melee(MELEE, name);
    EXPECT_DOUBLE_EQ(aPlayer->get_health(), 100.0);    
}

TEST(HealthTests, damagedHealth) {
    string name = "testMelee";
    Melee *aPlayer = new Melee(MELEE, name);

    double testDamage = 10.0;
    aPlayer->damage_player(testDamage);
    EXPECT_DOUBLE_EQ(aPlayer->get_health(), 90.0);    
}

//test level default & after leveling up
TEST(LevelTests, defaultLevel) {
    string name = "testMelee";
    Melee *aPlayer = new Melee(MELEE, name);

    EXPECT_EQ(aPlayer->get_level(), 0);    
}

TEST(LevelTests, levelUp) {
    string name = "testMelee";
    Melee *aPlayer = new Melee(MELEE, name);

    aPlayer->level_up();
    EXPECT_EQ(aPlayer->get_level(), 1);    
}






