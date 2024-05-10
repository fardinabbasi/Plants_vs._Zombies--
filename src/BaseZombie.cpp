#include "BaseZombie.hpp"

void BaseZombie::update(){
    if (plant == nullptr)
        sprite.move(Vector2f(-config["Speed"], 0));
    else
        plant->hurt(config["Damage"]);
}

void BaseZombie::set_target(Plant* plant){ //only when zombie arrived
    this->plant = plant;
}

void BaseZombie::hurt(unsigned int damage){
    health -= damage;
}

bool BaseZombie::dead(){
    if (health <= 0)
        return true;
    else
        return false;
}