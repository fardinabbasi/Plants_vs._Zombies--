#ifndef PVZ_HPP
#define PVZ_HPP

#include "Menu.hpp"
#include "Defs.hpp"
#include "Battle.hpp"


class PVZ{
    public:
    PVZ(map<string, map<string, float>> config);
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