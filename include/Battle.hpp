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


class Battle: public BaseScreen{
    public:
    Battle(map<string, map<string, int>>& config);
    ~Battle();
    Vector2f find_position(int x, int y);
    State render(RenderWindow& window);
    void mouse_press(int x, int y);
    void mouse_release(int x, int y);
    void update();
    void find_target();
    void attack();
    void make_zombies();
    
    private:
    bool in_battle_feild(int x, int y);
    map<string, map<string, int>> config;
    Sun* sun;
    list<BaseZombie*> zombies;
    list<Plant*> plants;
    State state;
    Clock clock;
    unsigned int interval;
    Card* chosen_card;
};

#endif