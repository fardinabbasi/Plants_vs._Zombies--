#ifndef PLANT_HPP
#define PLANT_HPP

#include <algorithm>
#include <map>
#include <list>
#include <string>
#include "Defs.hpp"
#include "BaseZombie.hpp"

class BaseZombie;

class Plant
{
public:
    Plant(map<string, float> config, string plant_tex_file, const Vector2f &position);
    virtual void render(RenderWindow &window);
    virtual void update();
    virtual void set_target(BaseZombie *z);
    void hurt(unsigned int damage);
    bool dead();
    virtual bool sun_press(int x, int y) { return false; }
    Vector2f get_position();
    FloatRect get_global_bounds();

protected:
    map<string, float> config;
    Sprite plant_sp;
    Texture plant_tex;
    int health;
    Clock attack_clock;
    Vector2f position;
    BaseZombie *zombie;
};

#endif
