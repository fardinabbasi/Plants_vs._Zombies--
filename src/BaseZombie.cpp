#include "BaseZombie.hpp"

BaseZombie::BaseZombie(const map<string, unsigned int> config, const string tex_path, const FloatRect bg_bound):
config(config), bg_bound(bg_bound)
{   
    plant = nullptr; 
    if (!texture.loadFromFile(IMAGES_PATH + tex_path)) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin((sf::Vector2f)texture.getSize() / 2.f);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, HEIGHT_GRIDS.size());
    
    sprite.setPosition(bg_bound.left+bg_bound.width, HEIGHT_GRIDS[dis(gen)]);
    
}

void BaseZombie::update(){
    if (plant == nullptr)
        sprite.move(Vector2f(-config["Speed"], 0));
    else
        plant->hurt(config["Damage"]);
}

void BaseZombie::set_target(Plant* plant){ //only when zombie arrived
    this->plant = plant;
}

void BaseZombie::hurt(unsigned int damage){
    health -= damage;
}

bool BaseZombie::dead(){
    if (health <= 0)
        return true;
    else
        return false;
}

bool BaseZombie::win(){
    if(sprite.getGlobalBounds().left <= (WIDTH_GRIDS.front() - 5))
        return true;
    else
        return false;
}