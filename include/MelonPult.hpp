#ifndef MELONPULT_HPP
#define MELONPULT_HPP

#include <list>
#include <algorithm>
#include "Defs.hpp"
#include "BaseZombie.hpp"

class MelonPult : public Plant
{
public:
    MelonPult(map<string, float> config, string melon_path, const Vector2f &position, FloatRect bg_bound);
    void update();
    void set_target(BaseZombie *z);
    void render(RenderWindow &window);

private:
    FloatRect bg_bound;
    list<float> clac_trajectory(int start_p, int start_z);
    BaseZombie *zombie;
    Texture melon_tex;
    Sprite melon;
    list<pair<Sprite, list<float>>> melons;
};

#endif