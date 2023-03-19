#include "../Player-Class/Player.h"
#include <cmath>

using namespace std;

//constructor calls the player constructor with the name parameter
Mage::Mage(PlayerType type, string &name) : Player(MAGE, name) { }

//attack function utlizes calculate damage function to inflict damage on enemy
double Mage::attack(Enemy * opp) {
    double damage = calculateDamage(opp);

    opp->takeDamage(damage);
    return damage;
}

//calculate damage function returns the total damage to be taken by the enemy using numerous factors
double Mage::calculateDamage(Enemy * opp) {
    int playerLevel = this->level;
    double PlayerHealth = this->health;
    int oppLevel = opp->getLevel();
    double oppHealth = opp->getHealth();
    
    double damage_modifier = oppHealth / PlayerHealth;

    double damage = 25 * damage_modifier;

    return damage;
}

bool Mage::runAway() {
    srand(time(nullptr));

    int random_number = rand() % 4;

    if(random_number == 0) {
        return true;
    } else {
        return false;
    }
}