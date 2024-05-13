#ifndef PLANT_HPP
#define PLANT_HPP

#include <algorithm>
#include <map>
#include <list>
#include <string>
#include "Defs.hpp"

class Plant
{
    public:
    Plant(){};
    Plant(map<string, int> config,string plant_tex_file,const Vector2f& position);
    void render(RenderWindow& window);
    void update();

    protected:
    Sprite plant_sp;
    Texture plant_tex;
    int damage;
    int health;
    int hit_rate;
    float speed;
    int price;
    Clock attack_clock;
    Vector2f position;
    
};

#endif
