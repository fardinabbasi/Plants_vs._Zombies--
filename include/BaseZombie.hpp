#ifndef BASEZOMBIE_HPP
#define BASEZOMBIE_HPP

#include "Defs.hpp"
#include <map>
#include <random>

class BaseZombie{
    public:
    BaseZombie(map<string, int> config, string tex_path, FloatRect bg_bound);
    void update();
    void set_target(Plant* plant);
    void hurt(unsigned int damage);
    bool dead();
    bool win();
    float get_height();
    void render(RenderWindow &window);
    private:
    const FloatRect bg_bound;
    unsigned int health;
    Texture texture;
    Sprite sprite;
    Plant* plant;
    map<string, int> config;
    Clock clock;
};


#endif