#include "Sunflower.hpp"

Sunflower::Sunflower(map<string, float> config,string shots_tex_file,const Vector2f& position) : Plant(config,"Sunflower.png", position)
{
    plant_sp.setTextureRect(SUNFLOWER_RECT);
    if (!sun_tex.loadFromFile(IMAGES_PATH + shots_tex_file)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
}

void Sunflower::update()
{
    if(attack_clock.getElapsedTime().asSeconds() >= config["HitRate"])
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

bool Sunflower::sun_press(int x,int y)
{
    auto it = suns.begin();
    while(it != suns.end())
    {
        if (it->getGlobalBounds().contains(static_cast<float>(x), static_cast<float>(y)))
        {
            it = suns.erase(it);
            return true;
        }
        else
        {  
            ++it;
        }
    }
    return false;
}


void Sunflower::render(RenderWindow &window)
{
    update();
    window.draw(plant_sp);
    for_each(suns.begin(), suns.end(), [&window](Sprite& sun){ window.draw(sun);});

}