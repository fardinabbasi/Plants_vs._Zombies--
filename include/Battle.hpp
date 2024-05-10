#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <list>
#include "BaseZombie.hpp"
#include "Defs.hpp"
#include "BaseScreen.hpp"
#include "Sun.hpp"
#include <algorithm>

class Battle: public BaseScreen{
    public:
    Battle(map<string, map<string, int>>& config);
    ~Battle();
    void render(RenderWindow& window);
    State mouse_press(int x, int y);
    void update();
    void find_target();
    private:
    map<string, map<string, int>> config;
    Sun* sun;
    list<BaseZombie> zombies;
    list<Plant> plants;
    State state;
    Clock clock;
};

#endif