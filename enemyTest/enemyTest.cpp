#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../lib/Enemy.h"

using namespace std;

TEST(EnemyTest, ValidInputs) {
  
  Enemy *level = new Enemy(5);
  Enemy *health = new Enemy(100);
  Enemy *damage = new Enemy (20);
  Enemy *type = new Enemy("Melee");

  EXPECT_EQ(level->getLevel(), 5);
  EXPECT_EQ(health->getHealth(), 100);
  EXPECT_EQ(damage->getDamage(),20);
  EXPECT_EQ(type->getType(), "Melee");
}


// TEST(EnemyTest, ValidInputs) {
//   int level = 5;
//   int health = 100;
//   int damage = 20;
//   string type = "Melee";
  
  
//   Enemy enemy(5, 100, 20, "Melee");
  
//   EXPECT_EQ(enemy::getLevel(), 5);
//   EXPECT_DOUBLE_EQ(enemy::getHealth(), 100);
//   EXPECT_EQ(enemy::getDamage(),20);
//   EXPECT_EQ(enemy::getType(), "Melee");
// }

TEST(EnemyTest,takeDamage){
Enemy enemy(1, 80, 10, "type");
  enemy.takeDamage(50.0);

   EXPECT_DOUBLE_EQ(enemy.getHealth(), 30);
}

TEST(EnemyTest,enemyDdmage){
Enemy enemy(1, 80, 10, "type");
  enemy.enemyDamage(10);

   EXPECT_EQ(enemy.getDamage(), 20);
}
