#include "BaseZombie.hpp"

BaseZombie::BaseZombie(map<string, float> config, string tex_path, FloatRect bg_bound):
config(config), bg_bound(bg_bound)
{   
    plant = nullptr; 
    if (!texture.loadFromFile(IMAGES_PATH + tex_path)) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    sprite.setTexture(texture);
    if (tex_path.starts_with("Zombie")){
        sprite.setTextureRect(ZOMBIE_RECT);
        sprite.setScale(1.75, 1.75);
    }
    else if (tex_path.starts_with("Gargantuar"))
        sprite.setScale(0.25, 0.25);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis1(0, HEIGHT_GRIDS.size());
    uniform_int_distribution<int> dis2(BATTLE_FIELD.left+BATTLE_FIELD.width, bg_bound.left + bg_bound.width);
    sprite.setPosition(dis2(gen), bg_bound.top + HEIGHT_GRIDS[dis1(gen)]);
    hit.restart();

    health = config["Health"];

}

void BaseZombie::update(){
    float speed;
    if(cool_penalty.getElapsedTime().asSeconds() >= COOL_PENALTY)
        speed = config["Speed"];
    else
        speed = config["Speed"]/2;

    if (plant == nullptr)
        sprite.move(Vector2f(-speed, 0));
    else if(hit.getElapsedTime().asSeconds() >= config["HitRate"]){
            plant->hurt(config["Damage"]);
            plant = plant->dead()? nullptr: plant;
            hit.restart();
    }
    
}

void BaseZombie::set_target(Plant* p){
    if(plant == nullptr && sprite.getGlobalBounds().intersects(p->get_global_bounds()))
        plant = p;
}

void BaseZombie::hurt(unsigned int damage, bool cool){
    health -= damage;
    if(cool){
        cool_penalty.restart();
    }
}

bool BaseZombie::dead(){
    return health <= 0;
}

bool BaseZombie::win(){
    return sprite.getGlobalBounds().left < BATTLE_FIELD.left + bg_bound.left;
}

float BaseZombie::get_height(){
    return sprite.getGlobalBounds().top;
}

float BaseZombie::get_width(){
    return sprite.getGlobalBounds().left;
}

void BaseZombie::render(RenderWindow &window){
    update();
    window.draw(sprite);
}