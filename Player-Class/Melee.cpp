#include "../Player-Class/Player.h"
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//constructor calls the player constructor with the name parameter
Melee::Melee(PlayerType type, string &name) : Player(MELEE, name) { }

//attack function utlizes calculate damage function to inflict damage on enemy
double Melee::attack(Enemy * opp) {
    double damage = calculateDamage(opp);

    opp->takeDamage(damage);
    return damage;
}

//calculate damage function returns the total damage to be taken by the enemy using numerous factors
double Melee::calculateDamage(Enemy * opp) {
    int playerLevel = this->level;
    double PlayerHealth = this->health;
    int oppLevel = opp->getLevel();
    double oppHealth = opp->getHealth();
    
    double damage_modifier = oppHealth / PlayerHealth;

    double damage = 25 * damage_modifier;

    return damage;
}

bool Melee::runAway() {
    srand(time(nullptr));

    int random_number = rand() % 2;

    if(random_number == 0) {
        return true;
    } else {
        return false;
    }
}