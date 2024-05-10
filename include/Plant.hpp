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
    Plant(map<string, int> config,string plant_tex_file,const FloatRect bg_bound);
    void render(RenderWindow& window);
    void update();

    protected:
    Sprite plant_sp;
    Sprite deck_sp;
    Texture plant_tex;
    Font font;
    Text deck_txt;
    int damage;
    int health;
    int hit_rate;
    int speed;
    int cool_down;
    int price;
    Clock clock;
    
};

#endif
