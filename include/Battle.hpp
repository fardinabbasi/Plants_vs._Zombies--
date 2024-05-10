#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "Defs.hpp"
#include "BaseScreen.hpp"
#include "Sun.hpp"

class Battle: public BaseScreen{
    public:
    Battle(map<string, map<string, int>>& config);
    ~Battle();
    void render(RenderWindow& window);
    State mouse_press(int x, int y);
    private:
    map<string, map<string, int>> config;
    Sun* sun;
    State state;
};

#endif