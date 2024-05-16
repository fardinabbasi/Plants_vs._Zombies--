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
    Sun(map<string, float> config, const FloatRect bg_bound);
    void render(RenderWindow& window);
    bool mouse_press(int x, int y);
    void modify_budget(int num = 1) { budget += num; }
    bool can_buy(float price);

    private:
    void update();
    map<string, float> config;
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