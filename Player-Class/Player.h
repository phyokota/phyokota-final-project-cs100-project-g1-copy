#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "../Enemy-Class/Enemy.h"

using namespace std;

enum PlayerType {MELEE, RANGE, MAGE};

const double MAX_HEALTH = 100.0;

class Player {
    protected:
        PlayerType type;
        double health;
        int level;
        double cash = 0.0;
        string name;
    public:
        Player(PlayerType type, string &name);
        void set_name(string &name);
        void damage_player(double damage);
        void level_up();
        PlayerType get_type() const;
        double get_health() const;
        int get_level() const;
        string get_name() const;
        void add_cash(double);
        double get_cash() const;
        bool is_alive() const;
        void printStats() const;
        virtual double attack(Enemy * opp) = 0;
        virtual bool runAway() = 0;
};

class Melee : public Player {
    private:
        int swordMastery = 1;
    public:
        Melee(PlayerType type, string &name);
        double attack(Enemy * opp);
        bool runAway();
    private:
        double calculateDamage(Enemy * opp);
};

class Range : public Player {
    private:
        int rangeMastery = 1;
    public:
        Range(PlayerType type, string &name);
        double attack(Enemy * opp);
        bool runAway();
    private:
        double calculateDamage(Enemy * opp);    
};

class Mage : public Player {
    private:
        int mageMastery = 1;
    public:
        Mage(PlayerType type, string &name);
        double attack(Enemy * opp);
        bool runAway();
    private:
        double calculateDamage(Enemy * opp);
};

#endif