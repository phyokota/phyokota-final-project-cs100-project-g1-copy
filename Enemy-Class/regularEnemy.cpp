#include "../Enemy-Class/Enemy.h"
#include <ctime>
#include <cstdlib>

using namespace std;

regularEnemy::regularEnemy(enemyType type, int level) : Enemy(REGULAR, level) {}

double regularEnemy::attack() {
    double regularEnemyAttackDamage = 15.0;
    
    srand((time(nullptr)));
    int random_number = rand() % 2;

    if(random_number == 0) {
        return 0.0; 
    } else {
        return regularEnemyAttackDamage;
    }
}