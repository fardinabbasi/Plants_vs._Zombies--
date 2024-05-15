#include "Plant.hpp"

Plant::Plant(map<string, float> config,string plant_tex_file,const Vector2f& position)
{
    config = config;
    int health = config["Health"];
    if (!plant_tex.loadFromFile(IMAGES_PATH + plant_tex_file)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    plant_sp.setTexture(plant_tex);
    plant_sp.setTextureRect(WALNUT_RECT);
    plant_sp.setScale(0.25, 0.25);
    plant_sp.setPosition(position);
}

bool Plant::dead()
{
    return (health <= 0);
}

void Plant::hurt(unsigned int damage)
{
    health -= damage;
}

void Plant::set_target(BaseZombie* z)
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
void Plant::render(RenderWindow &window)
{
    window.draw(plant_sp);
}

void Plant::update()
{
    if (plant_sp.getGlobalBounds().right >= zombie->get_width())
    {
        zombie->hurt(config["Damage"]);
    } 
}

Vector2f Plant::get_position()
{
    return position;
}
