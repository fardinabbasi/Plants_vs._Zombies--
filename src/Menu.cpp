#include "Menu.hpp"

Menu::Menu(): BaseScreen("StartingScreen.png", "StartingScreen.ogg")
{
    button.setPosition(250, 550);
    button.setSize(Vector2f(610, 75));
}

bool Menu::start_button(Vector2i mousePos){
    FloatRect buttonBounds = button.getGlobalBounds();
    if(buttonBounds.contains(static_cast<Vector2f>(mousePos))){
        music.stop();
        return true;
    }
    else
        return false;
}