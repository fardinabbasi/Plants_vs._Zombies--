#ifndef MENU_HPP
#define MENU_HPP
#include "BaseScreen.hpp"
#include "Defs.hpp"

class Menu: public BaseScreen{
    public:
    Menu();
    bool start_button(Vector2i mousePos);
    private:
    RectangleShape button;
};

#endif