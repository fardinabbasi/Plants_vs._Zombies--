#ifndef PVZ_HPP
#define PVZ_HPP
#include "Defs.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

enum State {
  IN_GAME,
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
    void starting_draw();
    void event_handler();
    private:
    map<string, map<string, int>> config;
    State state;
    RenderWindow window;
};

#endif