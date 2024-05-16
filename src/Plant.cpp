#include "Plant.hpp"

Plant::Plant(map<string, float> config, string plant_tex_file, const Vector2f& position):
config(config),position(position)
{
    this->health = config["Health"];
    if (!plant_tex.loadFromFile(IMAGES_PATH + plant_tex_file)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    plant_sp.setTexture(plant_tex);
    plant_sp.setTextureRect(WALNUT_RECT);
    plant_sp.setPosition(position);
    plant_sp.setScale(0.6, 0.6);
    cout<<"x is:"<<plant_sp.getPosition().x<<"y is:"<<plant_sp.getPosition().y<<endl;

}

bool Plant::dead(){
    return health <= 0;
}

void Plant::hurt(unsigned int damage)
{
    health -= damage;
    cout<<"health is:"<<health<<endl;
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
    update();
    window.draw(plant_sp);
}

void Plant::update()
{
    if(zombie != nullptr)
    {
        if (plant_sp.getGlobalBounds().left >= zombie->get_width())
        {
            zombie->hurt(config["Damage"]);
        } 
    }
    
}

Vector2f Plant::get_position()
{
    return position;
}

FloatRect Plant::get_global_bounds()
{
    return plant_sp.getGlobalBounds();
}


