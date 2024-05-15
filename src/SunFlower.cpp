#include "SunFlower.hpp"

SunFlower::SunFlower(map<string, float> config,string shots_tex_file,const Vector2f& position) : Plant(config,"Sunflower.png", position)
{
    attack_clock.reset();
    zombie = nullptr;
    if (!shot_tex.loadFromFile(IMAGES_PATH + shots_tex_file)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
}

void SunFlower::update()
{
    else if(attack_clock.getElapsedTime().asSeconds() >= config["HitRate"])
    {
        attack_clock.restart();
        Sprite new_sun;
        IntRect subrect(11, 9, 40, 40);
        new_sun.setTexture(sun_tex);
        new_sun.setTextureRect(subrect);
        new_sun.setPosition(position);
        suns.push_back(new_sun);
    }

}

bool SunFlower::sun_pressed(int x,int y)
{
    auto it = suns.begin();
    while(it != suns.end())
    {
        if (it->getGlobalBounds().contains(static_cast<float>(x), static_cast<float>(y)))
        {
            it = shots.erase(it);
            return true;
        }
        else
        {  
            ++it;
        }
    }
    return false;
}


void SunFlower::render(RenderWindow &window)
{
    window.draw(plant_sp);
    for_each(suns.begin(), suns.end(), [&window](Sprite& sun){ window.draw(sun);});

}