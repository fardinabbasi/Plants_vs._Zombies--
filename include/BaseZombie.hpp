#ifndef BASEZOMBIE_HPP
#define BASEZOMBIE_HPP

#include "Defs.hpp"
#include "Plant.hpp"
#include <map>
#include <random>

class Plant;

class BaseZombie
{
    public:
    BaseZombie(map<string, float> config, const string tex_path, FloatRect bg_bound);
    void set_target(Plant* plant);
    void hurt(unsigned int damage, bool cool = false);
    bool dead();
    bool win();
    float get_height();
    float get_width();
    void render(RenderWindow &window);
    
    private:
    void update();
    const FloatRect bg_bound;
    unsigned int health;
    Texture texture;
    Sprite sprite;
    Plant* plant;
    map<string, float> config;
    Clock hit;
    Clock cool_penalty;
};


#endif