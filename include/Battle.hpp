#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <algorithm>
#include <list>
#include <limits>
#include <math.h>
#include "BaseZombie.hpp"
#include "Defs.hpp"
#include "BaseScreen.hpp"
#include "Sun.hpp"
#include "Card.hpp"
#include "Plant.hpp"

class Battle : public BaseScreen
{
public:
    Battle(map<string, map<string, float>> &config);
    ~Battle();
    State render(RenderWindow &window);
    void mouse_press(int x, int y);
    void mouse_release(int x, int y);
    void update();
    void find_target();
    void attack();
    void make_zombies();
    Vector2f find_position(int x, int y);

private:
    map<string, map<string, float>> config;
    Sun *sun;
    list<Plant *> plants;
    list<Card*> deck;
    list<BaseZombie *> zombies;
    State state;
    Clock attack_clk;
    unsigned int attack_interval;
    Card* chosen_card;
    bool in_battle_feild(int x, int y);
};

#endif
