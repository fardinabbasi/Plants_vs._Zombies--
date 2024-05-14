#include "Battle.hpp"

Battle::Battle(map<string, map<string, int>>& config): 
config(config), BaseScreen("BackGround.png", "Loonboon.ogg")
{
    clock.restart();
    state = BATTLE;
    sun = new Sun(config["Sun"], background_sp.getGlobalBounds());
    interval = 0;
    chosen_card = nullptr;
}

State Battle::render(RenderWindow &window){
    update();
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(background_sp);
    for_each(zombies.begin(), zombies.end(), [&window](BaseZombie* zombie){ zombie->render(window); });
    sun->render(window);
    window.display();
    return state;
}

void Battle::mouse_press(int x, int y){
    if(!sun->mouse_press(x, y)){
        auto it = find_if(deck.begin(), deck.end(), [x,y](Card* card){ card.contains(x,y) && card.ready();});
        if(it != deck.end())
            chosen_card = *it;
        else
            chosen_card = nullptr;
    }
}

void Battle::mouse_release(int x, int y){
    if(chosen_card != nullptr && in_battle_feild(x,y)){
        Vector2f pos = find_position(x, y);
        if(!any_of(plants.begin(), plants.end(), [pos](Plant* plant){ plant.getPosition() == pos;})){
            plants.push_back(new Plant(config[chosen_card.get_name()], chosen_card.get_name() + ".png", pos));
            chosen_card->reset();
        }
    }
    chosen_card = nullptr;
}

Vector2f Battle::find_position(int x, int y){
    Vector2f nearest_point;
    double min_distance = numeric_limits<double>::max();
    for (unsigned int i = 0; i < WIDTH_GRIDS.size(); ++i) {
        for (unsigned int j = 0; j < HEIGHT_GRIDS.size(); ++j) {
        Vector2f current_point(background_sp.getGlobalBounds().left + WIDTH_GRIDS[i], background_sp.getGlobalBounds().top + HEIGHT_GRIDS[j]);
        double current_distance = sqrt(pow(current_point.x - x, 2) + pow(current_point.y - y, 2));

        if (current_distance < min_distance) {
            min_distance = current_distance;
            nearest_point = current_point;
        }
        }
    }
    return nearest_point;
}

bool Battle::in_battle_feild(int x, int y){
    return x >= BATTLE_FIELD.left + background_sp.getGlobalBounds().left
    && x <= BATTLE_FIELD.left + BATTLE_FIELD.width + background_sp.getGlobalBounds().left
    && y >= BATTLE_FIELD.top + background_sp.getGlobalBounds().top
    && y <= BATTLE_FIELD.top + BATTLE_FIELD.height + background_sp.getGlobalBounds().top;
}

Battle::~Battle(){
    for_each(zombies.begin(), zombies.end(), [](BaseZombie* zombie){ delete zombie; });
    for_each(plants.begin(), plants.end(), [](Plant* plant){ delete plant; });
    delete sun;
}

void Battle::update(){
    attack();
    find_target();
}

void Battle::find_target(){
    auto plant_it = plants.begin();
    auto zombie_it = zombies.begin();

    while(plant_it != plants.end()){
        if((*plant_it)->dead()){
            plant_it = plants.erase(plant_it);
            continue;
        }
        while (zombie_it != zombies.end()){
            if((*zombie_it)->dead()){
                zombie_it = zombies.erase(zombie_it);
                continue;
            }   
            (*zombie_it)->set_target(*plant_it);
            (*plant_it)->set_target(*zombie_it);
            ++zombie_it;
        }
        ++plant_it;
    }
}

void Battle::attack(){
    if(any_of(zombies.begin(), zombies.end(),[](BaseZombie& zombie){ zombie.win(); })){
        state = GAMEOVER;
        return;
    }
    else if (clock.getElapsedTime().asSeconds() >= config["Attacks"]["TotalTime"]){
        state = VICTORY;
        return;
    }
    unsigned int num_intervals = config["Attacks"]["TotalTime"]/config["Attacks"]["Interval"];
    float elapsed = clock.getElapsedTime().asSeconds();
    for (unsigned int i = 1; i <= num_intervals; i++){
        if ((i-1)*config["Attacks"]["Interval"] <= elapsed && i*config["Attacks"]["Interval"] > elapsed){
            if(i != interval){
                interval = i;
                make_zombies();
            }
            break;
        }
    }
}

void Battle::make_zombies(){
    unsigned int num_zombies = config["Attacks"]["StartingNum"] + (interval-1) * config["Attacks"]["IncNum"];
    unsigned int num_gargantuar = num_zombies * GARGANTUAR_RATIO;
    for (unsigned int i = 0; i < num_gargantuar; i++){
        zombies.push_back(new BaseZombie(config["Gargantuar"], "Gargantuar.png", background_sp.getGlobalBounds()));
    }
    for (unsigned int i = 0; i < (num_zombies-num_gargantuar); i++){
        zombies.push_back(new BaseZombie(config["Zombie"], "Zombie.png", background_sp.getGlobalBounds()));
    }
}