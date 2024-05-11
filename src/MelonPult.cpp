#include "MelonPult.hpp"



void MelonPult::update(){
    if(clock.getElapsedTime().asSeconds() >= config["HitRate"]){
        melons.push_back(melon);
        clock.restart();
    }
    auto melon_it = melons.begin();
    while(it != melons.end()){
        it->move(Vector2f(config["Speed"], ?));
        if(?){//if arrived
            if(zombie->kill(config["Damage"])){
                zombie = nullptr;
            }
        }
    }
}