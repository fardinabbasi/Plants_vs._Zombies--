#include "PeaShooter.hpp"

PeaShooter::PeaShooter(const map<string, int>& config, const string& plant_tex_file, const FloatRect& bg_bound)
    : Plant(config, plant_tex_file, bg_bound) 
{
    

}

void PeaShooter::update() 
{
    if (attack_clock.getElapsedTime() >= cool_down) 
    {
        attack_clock.restart();
    }
}
