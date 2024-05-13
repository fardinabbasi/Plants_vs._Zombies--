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
    Sprite deck_sp;
    Font font;
    Text deck_txt;
    int damage;
    int health;
    int hit_rate;
    float speed;
    //Time hit_rate;
    int price;
    Clock attack_clock;
    Vector2f position;
    
};

#endif
