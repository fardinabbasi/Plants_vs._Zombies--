#include "Battle.hpp"

Battle::Battle(map<string, map<string, int>>& config): config(config), BaseScreen("Background.png", "Loonboon.ogg")
{
//
}

void Battle::render(RenderWindow &window){
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(background_sp);
    window.display();
}