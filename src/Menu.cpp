#include "Menu.hpp"

Menu::Menu() : BaseScreen("StartingScreen.png", "StartingScreen.ogg")
{
    FloatRect bg_bound = background_sp.getGlobalBounds();
    button.setSize(Vector2f(610, 75));
    button.setPosition(bg_bound.left + 250, bg_bound.top + 550);
    state = STARTING;
}

void Menu::mouse_press(int x, int y)
{
    FloatRect buttonBounds = button.getGlobalBounds();
    if (buttonBounds.contains(x, y))
    {
        music.stop();
        state = BATTLE;
    }
}