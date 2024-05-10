#ifndef PLANT_HPP
#define PLANT_HPP

#include <algorithm>
#include <map>
#include <list>
#include "Defs.hpp"

class Plant
{
    public:
    Plant(){};
    Plant(map<string, int> config);
    void render(RenderWindow& window);
    void update();

    private:
    damage;
    health;
    hit_rate;
    speed;
    cool_down;
    price;
};

#endif
