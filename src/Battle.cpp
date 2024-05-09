#include "Battle.hpp"

Battle::Battle(map<string, map<string, int>>& config): 
config(config), BaseScreen("Background.png", "Loonboon.ogg")
{
    sun = new Sun(config["Sun"], background_sp.getGlobalBounds());
}

void Battle::render(RenderWindow &window){
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(background_sp);
    sun->render(window);
    window.display();
}

Battle::~Battle(){
    delete sun;
}