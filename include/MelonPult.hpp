#ifndef MELONPULT_HPP
#define MELONPULT_HPP

#include <list>
#include "Defs.hpp"
#include "BaseZombie.hpp"

class MelonPult: public Plant{
    public:
    MelonPult(string melon_path); 
    void update();
    void set_target(BaseZombie* z);

    private:
    float curve_coeff;
    list<float> clac_trajectory(int start_p, int start_z);
    BaseZombie* zombie;
    Texture melon_tex;
    Sprite melon;
    list<pair<Sprite, list<float>>> melons;
};

#endif