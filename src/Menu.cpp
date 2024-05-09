#include "Menu.hpp"

Menu::Menu(): BaseScreen("StartingScreen.png", "StartingScreen.ogg")
{
    FloatRect bg_bound = background_sp.getGlobalBounds();
    button.setSize(Vector2f(610, 75));
    button.setPosition(bg_bound.left+250, bg_bound.top+550);
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