#include "MelonPult.hpp"

MelonPult::MelonPult(string melon_path){
     float curve_coeff = -0.4;
     zombie = nullptr;

    if (!melon_tex.loadFromFile(IMAGES_PATH + melon_path)) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    melon.setTexture(melon_tex);
    melon.setOrigin((Vector2f)melon_tex.getSize() / 2.f);
    melon.setPosition(plant_sp.getGlobalBounds().left+2, plant_sp.getGlobalBounds().height+5);

}

void MelonPult::update(){
    if(zombie->dead()){
        zombie = nullptr;
        return;
    }
    else if(attack_clock.getElapsedTime().asSeconds() >= config["HitRate"]){
        melons.push_back(make_pair(melon, clac_trajectory(melon.getGlobalBounds().left, zombie->get_width())));
        attack_clock.restart();
    }
    auto melon_it = melons.begin();
    while(melon_it != melons.end()){
        melon_it->first.move(Vector2f(config["Speed"], melon_it->second.front()));
        melon_it->second.pop_front();
        if(melon_it->second.empty()){
            zombie->hurt(config["Damage"]);
            melon_it = melons.erase(melon_it);
        }
        else
            ++melon_it;
    }
}

void MelonPult::set_target(BaseZombie* z){
    if (z->get_height() == plant_sp.getGlobalBounds().height){
        if(zombie == nullptr ||
        (z->get_width() >= plant_sp.getGlobalBounds().left && z->get_width() < zombie->get_width()))
            zombie = z;
    }
}

list<float> MelonPult::clac_trajectory(int start_p, int start_z){
    int collision_time = (start_z - start_p) / (config["Speed"] + zombie->get_speed());
    list<float> trajectory = {0};
    int collision_width = start_p + config["Speed"]*collision_time;
    for (int i = 0; i < collision_time; i++){
        float x = start_p + i * config["Speed"];
        float relative_offset = (curve_coeff * (x - start_p) * (x - collision_width)) - trajectory.back();
        trajectory.push_back(relative_offset);
    }
    trajectory.pop_front();
    return trajectory;
}
