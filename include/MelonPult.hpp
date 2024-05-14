#ifndef MELONPULT_HPP
#define MELONPULT_HPP

#include <list>
#include "Defs.hpp"
#include "BaseZombie.hpp"

class MelonPult: public Plant{
    public:
    MelonPult(map<string, int> config, string tex_path); //background is set in parent
    void update();
    private:
    BaseZombie* zombie;
    Texture melon;
    Sprite melon;
    list<Sprite> melons;
    //parent has clock
};

#endif