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
    for_each(zombies.begin(), zombies.end(), [&window](BaseZombie& zombie){ zombie.render(window); });
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
    find_target();
    for_each(zombies.begin(), zombies.end(), [](BaseZombie& zombie){ zombie.update(); });

}

void Battle::find_target(){
    auto plant_it = plants.begin();
    auto zombie_it = zombies.begin();

    while(plant_it != plants.end()){
        if(plant_it->dead()){
            plant_it = plants.erase(plant_it);
            continue;
        }
        while (zombie_it != zombies.end()){
            if(zombie_it->dead()){
                zombie_it = zombies.erase(zombie_it);
                continue;
            }   
            zombie_it->set_target(&(*plant_it));
            plant_it->set_target(&(*zombie_it));
            ++zombie_it;
        }
        ++plant_it;
    }
}