#include "MelonPult.hpp"



void MelonPult::update(){
    if(clock.getElapsedTime().asSeconds() >= config["HitRate"]){
        melons.push_back(melon);
    }
}