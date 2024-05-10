#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

#include "Plant.hpp"
#include "Defs.hpp"

class PeaShooter : public Plant 
{
public:
    PeaShooter(const map<string, int>& config, const string& plant_tex_file, const FloatRect& bg_bound);
    void update();

};

#endif

