#include "MelonPult.hpp"



void MelonPult::update(){
    if(zombie->dead()){
        zombie = nullptr;
        return;
    }
    else if(clock.getElapsedTime().asSeconds() >= config["HitRate"]){
        melons.push_back(melon);
        clock.restart();
    }
    auto melon_it = melons.begin();
    while(melon_it != melons.end()){
        melon_it->move(Vector2f(config["Speed"], ?));

        if(?){//if arrived
            zombie->hurt(config["Damage"]);
            melon_it = melons.erase(melon_it);
        }
        else
            ++melon_it;
    }
}