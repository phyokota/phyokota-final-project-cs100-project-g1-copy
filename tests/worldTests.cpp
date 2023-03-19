#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string.h>
#include "../World-Class/World.h"

using namespace std;

//World Constructor:
TEST(ConstructorTest, BattleField_Initial_Test){
    string name = "Bella";
    World *world = new BattleField(BATTLEFIELD, name);
    EXPECT_TRUE(world->getGamePos() == 1);
    EXPECT_TRUE(world->getName() == "Bella");
    delete world;
}

TEST(ConstructorTest, BattleField_Change_Game_Position_Test){
    string name = "Bella";
    World *world = new BattleField(BATTLEFIELD, name);
    world->gamePositionSetter(50);
    EXPECT_TRUE(world->getGamePos() == 2);
    world->gamePositionSetter(10);
    EXPECT_TRUE(world->getGamePos() == 3);
    delete world;
}

TEST(ConstructorTest, BattleField_Location_Test){
    string name = "Bella";
    World *world = new BattleField(BATTLEFIELD, name);
    EXPECT_TRUE(world->getLocation() == BATTLEFIELD);
    delete world;
}
//------------------------

TEST(ConstructorTest, Forest_Initial_Test){
    string name = "Bella";
    World *world = new Forest(FOREST, name);
    EXPECT_TRUE(world->getGamePos() == 1);
    EXPECT_TRUE(world->getName() == "Bella");
    delete world;
}


TEST(ConstructorTest, Forest_Change_Game_Position_Test){
    string name = "Bella";
    World *world = new Forest(FOREST, name);
    world->gamePositionSetter(50);
    EXPECT_TRUE(world->getGamePos() == 2);
    world->gamePositionSetter(10);
    EXPECT_TRUE(world->getGamePos() == 3);
    delete world;
}

TEST(ConstructorTest, Forest_Location_Test){
    string name = "Bella";
    World *world = new Forest(FOREST, name);
    EXPECT_TRUE(world->getLocation() == FOREST);
    delete world;
}
//---------------------
TEST(ConstructorTest, Wonderland_Initial_Test){
    string name = "Bella";
    World *world = new Wonderland(WONDERLAND, name);
    EXPECT_TRUE(world->getGamePos() == 1);
    EXPECT_TRUE(world->getName() == "Bella");
    delete world;
}


TEST(ConstructorTest, Wonderland_Change_Game_Position_Test){
    string name = "Bella";
    World *world = new Wonderland(WONDERLAND, name);
    world->gamePositionSetter(50);
    EXPECT_TRUE(world->getGamePos() == 2);
    world->gamePositionSetter(10);
    EXPECT_TRUE(world->getGamePos() == 3);
    delete world;
}

TEST(ConstructorTest, Wonderland_Location_Test){
    string name = "Bella";
    World *world = new Wonderland(WONDERLAND, name);
    EXPECT_TRUE(world->getLocation() == WONDERLAND);
    delete world;
}

// TEST(OutPutTests, Location_Map_Test){
//     string name = "Bella";
//     World *world = new Wonderland(WONDERLAND, name);
//     EXPECT_NO_THROW(world->locationMap());
//     world->gamePositionSetter(50);
//     EXPECT_NO_THROW(world->locationMap());
//     world->gamePositionSetter(10);
//     EXPECT_NO_THROW(world->locationMap());
//     delete world;
// }
// // //void World::gamePositionSetter(int)

// // //void World::gamePositionIndicator(){

// // //void World::locationMap(){