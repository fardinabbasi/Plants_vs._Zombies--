#ifndef MENU_HPP
#define MENU_HPP
#include "BaseScreen.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Defs.hpp"

using namespace sf;
using namespace std;

class Menu: public BaseScreen{
    public:
    Menu();
    bool start_button(Vector2i mousePos);
    private:
    RectangleShape button;
};

#endif