#include "Plant.hpp"

Plant::Plant(map<string, int> config,string plant_tex_file,const Vector2f& position)
{
    this-> position = position;
    this-> damage = config["Damage"];
    this-> health = config["Health"];
    this-> hit_rate = config["HitRat"];
    this-> speed = static_cast<float>(config["Speed"]);
    this-> price = config["Price"];
    if (!plant_tex.loadFromFile(IMAGES_PATH + plant_tex_file)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if (!font.loadFromFile(FONTS_PATH + "score.ttf")) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    IntRect subrect(0, 0, 350, 325);
    plant_sp.setTexture(plant_tex);
    plant_sp.setTextureRect(subrect);
    plant_sp.setOrigin((Vector2f)plant_tex.getSize() / 2.f);
    plant_sp.setScale(0.25, 0.25);
    plant_sp.setPosition(position);
    attack_clock.reset();

}

void Plant::render(RenderWindow &window)
{
    window.draw(plant_sp);
}

bool Plant::dead()
{
    return (health <= 0);
}

void Plant::hurt(unsigned int damage)
{
    health -= damage;
}
