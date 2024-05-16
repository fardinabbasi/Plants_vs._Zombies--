#include "PeaShooter.hpp"
PeaShooter::PeaShooter(map<string, float> config,string shots_tex_file,const Vector2f& position,FloatRect bg_bound) : Plant(config,"PeaShooter.png", position)
{
    first_shot_made = false;
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
    if(zombie != nullptr)
    {
            if (!first_shot_made) 
        {
            
            make_shot();
            first_shot_made = true;
        }
        else 
        {
            if (attack_clock.getElapsedTime().asSeconds() >= config["HitRate"]) {
                attack_clock.restart();
                make_shot(); 
            }
        }
        for_each(shots.begin(), shots.end(), [this](Sprite& shot){ shot.move(config["Speed"], 0); });
        // if(!shots.empty())
        // {
        //     if (shots.front().getPosition().x >= bg_bound.left+bg_bound.width)
        //     {
        //         shots.pop_front();
        //     }
        // }
        auto it = shots.begin();
        while(it != shots.end())
        {
            if (it->getGlobalBounds().left >= zombie->get_width())
            {
                zombie->hurt(config["Damage"]);
                it = shots.erase(it);
                if (zombie->dead())
                {
                    zombie = nullptr;
                }
                break;
            }
            else
            {  
                ++it;
            }
        }
    }
}

void PeaShooter::set_target(BaseZombie* z)
{
    if (z->get_height() == plant_sp.getGlobalBounds().top)
    {
       if(zombie == nullptr || z->get_width() >= plant_sp.getGlobalBounds().left && z->get_width() < zombie->get_width())
        {
            zombie = z;
        }
    }
}

void PeaShooter::render(RenderWindow &window)
{
    update();
    window.draw(plant_sp);
    if(zombie!=nullptr)
    for_each(shots.begin(), shots.end(), [&window](Sprite& shot){ window.draw(shot);});
    
}

void PeaShooter::make_shot() 
{
    Sprite new_shot;
    new_shot.setTexture(shot_tex);
    new_shot.setTextureRect(PEA_SHOOTER_SHOT);
    new_shot.setPosition(position);
    shots.push_back(new_shot);
}