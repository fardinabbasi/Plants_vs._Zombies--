#ifndef PVZ_HPP
#define PVZ_HPP
#include "Menu.hpp"
#include "Defs.hpp"
#include "Battle.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

enum State {
  BATTLE,
  Starting_Screen,
  VICTORY_SCREEN,
  GAMEOVER_SCREEN,
  EXIT
};

class PVZ{
    public:
    PVZ(map<string, map<string, int>> config);
    //~PVZ();
    void run();
    void event_handler();
    private:
    map<string, map<string, int>> config;
    State state;
    Menu menu;
    Battle battle;
    RenderWindow window;
};

#endif