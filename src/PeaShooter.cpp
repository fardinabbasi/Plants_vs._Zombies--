#include "PeaShooter.hpp"
PeaShooter::PeaShooter(map<string, float> config,string shots_tex_file,const Vector2f& position,FloatRect bg_bound) : Plant(config,"PeaShooter.png", position)
{
    bg_bound = bg_bound;
    attack_clock.restart();
    zombie = nullptr;
    if (!shot_tex.loadFromFile(IMAGES_PATH + shots_tex_file)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    plant_sp.setTextureRect(PEA_RECT);
}

void PeaShooter::update()
{
    if(attack_clock.getElapsedTime().asSeconds() >= config["HitRate"])
    {
        attack_clock.restart();
        Sprite new_shot;
        IntRect subrect(5, 70, 30, 95);
        new_shot.setTexture(shot_tex);
        new_shot.setTextureRect(subrect);
        new_shot.setPosition(position);
        shots.push_back(new_shot);
    }
    for_each(shots.begin(), shots.end(), [this](Sprite& shot){ shot.move(config["Speed"], 0); });

    if (shots.front().getPosition().x >= bg_bound.width)
    {
        shots.pop_front();
    }
    auto it = shots.begin();
    while(it != shots.end())
    {
        if (it->getGlobalBounds().left >= zombie->get_width())
        {
            zombie->hurt(config["Damage"]);
            it = shots.erase(it);
            break;
        }
        else
        {  
            ++it;
        }
    }
  
}

void PeaShooter::set_target(BaseZombie* z)
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

void PeaShooter::render(RenderWindow &window)
{
    window.draw(plant_sp);
    for_each(shots.begin(), shots.end(), [&window](Sprite& shot){ window.draw(shot);});
}