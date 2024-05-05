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
  Starting,
  VICTORY,
  GAMEOVER,
  EXIT
};

class PVZ{
    public:
    PVZ(map<string, map<string, int>> config);
    //~PVZ();
    void run();
    void event_handler();
    private:
    State state;
    Menu menu;
    Battle battle;
    BaseScreen victory_screen, lose_screen;
    RenderWindow window;
};

#endif