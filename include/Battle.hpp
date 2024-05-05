#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>
#include "Defs.hpp"
#include "BaseScreen.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Battle: public BaseScreen{
    public:
    Battle(map<string, map<string, int>>& config);
    void render(RenderWindow& window);//will override
    private:
    map<string, map<string, int>> config;
};

#endif