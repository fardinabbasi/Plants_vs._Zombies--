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
        IntRect subrect(5, 70, 30, 25);
        new_shot.setTexture(shot_tex);
        new_shot.setTextureRect(subrect);
        new_shot.setPosition(position);
        shots.push_back(new_shot);
    }
    for_each(shots.begin(), shots.end(), [this](Sprite& shot){ shot.move(config["Speed"], 0); });
    if(!shots.empty())
    {

        // if (shots.front().getPosition().x >= bg_bound.left)
        // {
        //     shots.pop_front();
        // }
    }
    auto it = shots.begin();
    if(zombie != nullptr)
    {
        cout<<"zombie sets"<<endl;
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
    // else
    // {
    //     //cout<<"no zombie"<<endl;
    // }


  
}

void PeaShooter::set_target(BaseZombie* z)
{
    cout<<"zombies hight"<<z->get_height()<<endl;
    cout<<"plant hight"<<plant_sp.getGlobalBounds().top<<endl;
    if (z->get_height() == plant_sp.getGlobalBounds().top)
    {
        cout<<"same hight"<<endl;
       if(zombie == nullptr ||
        (z->get_width() >= plant_sp.getGlobalBounds().left && z->get_width() < zombie->get_width()))
        {
            cout<<"infront of mee"<<endl;
            zombie = z;
        }
    }
}

void PeaShooter::render(RenderWindow &window)
{
    update();
    window.draw(plant_sp);
    for_each(shots.begin(), shots.end(), [&window](Sprite& shot){ window.draw(shot);});
    
}