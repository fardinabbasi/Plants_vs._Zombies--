#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>
#include "Defs.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class Battle{
    public:
    Battle(map<string, map<string, int>>& config);
    void render(RenderWindow &window);
    private:
    Texture background_tx;
    Sprite background_sp;
    Music music;
    map<string, map<string, int>> config;
};
#endif