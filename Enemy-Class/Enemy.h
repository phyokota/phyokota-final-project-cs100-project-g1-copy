#ifndef ENEMY_H
#define ENEMY_H

using namespace std;

enum enemyType {REGULAR, BOSS};

class Enemy {
    protected:
        enemyType type;
        double health = 100.0;
        int level;
    public:
        Enemy(enemyType type, int level);
        void takeDamage(double damage);
        double getHealth() const;
        int getLevel() const;
        virtual double attack() = 0;
};

class regularEnemy : public Enemy {
    public:
        regularEnemy(enemyType type, int level);
        double attack();
};

class bossEnemy : public Enemy {
    public:
        bossEnemy(enemyType type, int level);
        double attack();
};

#endif