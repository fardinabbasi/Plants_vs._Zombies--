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
<<<<<<< HEAD
    Plant(map<string, int> config,string plant_tex_file,const FloatRect bg_bound,const Vector2f& position);
=======
    Plant(map<string, int> config,string plant_tex_file,const Vector2f& position);
>>>>>>> a5db1f83683a8b71d37ff0fab6b8d18e8096fabb
    void render(RenderWindow& window);
    void update();

    protected:
    Sprite plant_sp;
    Texture plant_tex;
<<<<<<< HEAD
    Sprite deck_sp;
    Font font;
    Text deck_txt;
=======
>>>>>>> a5db1f83683a8b71d37ff0fab6b8d18e8096fabb
    int damage;
    int health;
    int hit_rate;
    float speed;
<<<<<<< HEAD
    //Time hit_rate;
=======
>>>>>>> a5db1f83683a8b71d37ff0fab6b8d18e8096fabb
    int price;
    Clock attack_clock;
    Vector2f position;
    
};

#endif
