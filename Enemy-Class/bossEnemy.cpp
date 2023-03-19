#include "../Enemy-Class/Enemy.h"
#include <ctime>
#include <cstdlib>

using namespace std;

bossEnemy::bossEnemy(enemyType type, int level) : Enemy(BOSS, level) {}

double bossEnemy::attack() {
    double bossEnemyAttackDamage = 20.0;
    
    srand((time(nullptr)));
    int random_number = rand() % 2;

    if(random_number == 0) {
        return 0.0; 
    } else {
        return bossEnemyAttackDamage;
    }
}