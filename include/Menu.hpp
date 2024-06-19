#ifndef MENU_HPP
#define MENU_HPP
#include "BaseScreen.hpp"
#include "Defs.hpp"

class Menu : public BaseScreen
{
public:
    Menu();
    void mouse_press(int x, int y);

private:
    RectangleShape button;
};

#endif