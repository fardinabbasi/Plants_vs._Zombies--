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
    void modify_budget(int num) { budget += num; }
    unsigned int get_budget(){ return budget; }
    private:
    map<string, int> config;
    FloatRect bg_bound;
    unsigned int budget;
    Sprite deck_sp;
    Texture sun_tex;
    Font font;
    Text deck_txt;
    list<Sprite> suns;
    Clock clock;
};

#endif