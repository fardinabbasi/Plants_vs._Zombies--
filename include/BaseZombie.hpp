#ifndef BASEZOMBIE_HPP
#define BASEZOMBIE_HPP

#include "Defs.hpp"
#include <map>

class BaseZombie{
    public:
    BaseZombie(){ plant = nullptr; }
    void update();
    void set_target(Plant* plant);
    void hurt(unsigned int damage);
    bool dead();
    protected:
    unsigned int health, damage, speed;
    Texture texture;
    Sprite sprite;
    Plant* plant;
    map<string, unsigned int> config;
};


#endif