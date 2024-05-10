#include "Battle.hpp"

Battle::Battle(map<string, map<string, int>>& config): 
config(config), BaseScreen("BackGround.png", "Loonboon.ogg")
{
    clock.restart();
    state = BATTLE;
    sun = new Sun(config["Sun"], background_sp.getGlobalBounds());
}

void Battle::render(RenderWindow &window){
    update();
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(background_sp);
    sun->render(window);
    window.display();
}

State Battle::mouse_press(int x, int y){
    sun->mouse_press(x, y);
    return state;
}

Battle::~Battle(){
    delete sun;
}

void Battle::update(){
    if(any_of(zombies.begin(), zombies.end(),[](BaseZombie& zombie){ zombie.win(); })){
        state = GAMEOVER;
        return;
    }
    else if (clock.getElapsedTime().asSeconds() >= config["Attacks"]["TotalTime"]){
        state = VICTORY;
        return;
    }
    sun->update();
}