#include "BaseZombie.hpp"

BaseZombie::BaseZombie(map<string, int> config, string tex_path, FloatRect bg_bound):
config(config), bg_bound(bg_bound)
{   
    plant = nullptr; 
    if (!texture.loadFromFile(IMAGES_PATH + tex_path)) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin((Vector2f)texture.getSize() / 2.f);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis1(0, HEIGHT_GRIDS.size());
    uniform_int_distribution<int> dis2(0, 300);
    sprite.setPosition(bg_bound.left+bg_bound.width-dis2(gen), HEIGHT_GRIDS[dis1(gen)]);
    hit.restart();

}

void BaseZombie::update(){
    float speed;
    if(cool_penalty.getElapsedTime().asSeconds() >= COOL_TIME)
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
    if(plant == nullptr && sprite.getGlobalBounds().intersects(p->getGlobalBounds()))
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
    return sprite.getGlobalBounds().left <= (WIDTH_GRIDS.front() - 5);
}

float BaseZombie::get_height(){
    return sprite.getGlobalBounds().top;
}

float BaseZombie::get_width(){
    return sprite.getGlobalBounds().left;
}

int BaseZombie::get_speed(){
    return config["speed"];
}

void BaseZombie::render(RenderWindow &window){
    update();
    window.draw(sprite);
}