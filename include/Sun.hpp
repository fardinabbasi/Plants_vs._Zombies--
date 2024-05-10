#ifndef SUN_HPP
#define SUN_HPP

#include <algorithm>
#include <random>
#include <map>
#include <list>
#include "Defs.hpp"

class Sun{
    public:
    Sun(){};
    Sun(map<string, int> config, const FloatRect bg_bound);
    void render(RenderWindow& window);
    void update();
    void mouse_press(int x, int y);
    private:
    map<string, int> config;
    FloatRect bg_bound;
    unsigned int sun_budget;
    Sprite deck_sp;
    Texture sun_tex;
    Font font;
    Text deck_txt;
    list<Sprite> suns;
    Clock clock;
    mt19937 gen;
};

#endif