#include "SnowPea.hpp"

SnowPea::SnowPea(map<string, float> config,string shots_tex_file,const Vector2f& position,const FloatRect bg_bound): Plant(config,"SnowPea.png", position)
{
    attack_clock.restart();
    zombie = nullptr;
    if (!shot_tex.loadFromFile(IMAGES_PATH + shots_tex_file)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
}

void SnowPea::update()
{
    if(attack_clock.getElapsedTime().asSeconds() >= config["HitRate"])
    {
        attack_clock.restart();
        Sprite new_shot;
        IntRect subrect(5, 103, 30, 127);
        new_shot.setTexture(shot_tex);
        new_shot.setTextureRect(subrect);
        new_shot.setPosition(position);
        shots.push_back(new_shot);
    }
    for_each(shots.begin(), shots.end(), [](Sprite& shot){ shot.move(config["Speed"], 0); });

    if (shots.front().getPosition().x >= bg_bound.width)
    {
        shots.pop_front();
    }
    auto it = shots.begin();
    while(it != shots.end())
    {
        if (it->getGlobalBounds().right >= zombie->get_width())
        {
            zombie->hurt(config["Damage"],true);
            it = shots.erase(it);
            break;
        }
        else
        {  
            ++it;
        }
    }
  
}

void SnowPea::set_target(BaseZombie* z)
{
    if (z->get_height() == plant_sp.getGlobalBounds().height)
    {
       if(zombie == nullptr ||
        (z->get_width() >= plant_sp.getGlobalBounds().left && z->get_width() < zombie->get_width()))
        {
            zombie = z;
        }
    }
}

void SnowPea::render(RenderWindow &window)
{
    window.draw(plant_sp);
    for_each(shots.begin(), shots.end(), [&window](Sprite& shot){ window.draw(shot);});
}