#include "../Enemy-Class/Enemy.h"

Enemy::Enemy(enemyType type, int level) {
    this->type = type;
    this->level = level;
}

void Enemy::takeDamage(double damage) {
    this->health -= damage;
}

double Enemy::getHealth() const {
    return this->health;
}

int Enemy::getLevel() const {
    return this->level;
}