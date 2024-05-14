#include "Battle.hpp"
Battle::Battle(map<string, map<string, int>>& config): 
config(config), BaseScreen("BackGround.png", "Loonboon.ogg")
{
<<<<<<< HEAD
    is_dragging = false;

    sun = new Sun(config["Sun"], background_sp.getGlobalBounds());
    if(!pea_shooter_tex.loadFromFile(IMAGES_PATH + "PeaShooter.png"))
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if(!snowy_pea_tex.loadFromFile(IMAGES_PATH + "SnowPea.png"))
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if(!sun_flower_tex.loadFromFile(IMAGES_PATH + "Sunflower.png"))
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if(!peanut_tex.loadFromFile(IMAGES_PATH + "Walnut.png"))
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    IntRect peaRect(0, 150, 95, 96);
    pea_shooter_sp.setTexture(pea_shooter_tex);
    pea_shooter_sp.setTextureRect(peaRect);
    pea_shooter_sp.setScale(0.75, 0.75);
    pea_shooter_sp.setPosition(background_sp.getGlobalBounds().left+80, background_sp.getGlobalBounds().top+130);

    IntRect snowyRect(0, 130, 120, 115);
    snowy_pea_sp.setTexture(snowy_pea_tex);
    snowy_pea_sp.setTextureRect(snowyRect);
    snowy_pea_sp.setScale(0.7, 0.7);
    snowy_pea_sp.setPosition(background_sp.getGlobalBounds().left+80, background_sp.getGlobalBounds().top+230);

    IntRect sunflowerRect(0, 170, 130, 130);
    sun_flower_sp.setTexture(sun_flower_tex);
    sun_flower_sp.setTextureRect(sunflowerRect);
    sun_flower_sp.setScale(0.7, 0.7);
    sun_flower_sp.setPosition(background_sp.getGlobalBounds().left+80, background_sp.getGlobalBounds().top+330);

    IntRect peanutRect(0, 0, 101, 115);
    peanut_sp.setTexture(peanut_tex);
    peanut_sp.setTextureRect(peanutRect);
    peanut_sp.setScale(0.7, 0.7);
    peanut_sp.setPosition(background_sp.getGlobalBounds().left+80, background_sp.getGlobalBounds().top+430);
    cool_downs["PeaShooter"].restart(); 
    cool_downs["SnowPea"].restart(); 
    cool_downs["Sunflower"].restart(); 
    cool_downs["Walnut"].restart();
 
}

void Battle::update_cooldowns() 
{
    for (auto& pair : cool_downs) 
    {
        if (pair.second.getElapsedTime().asMilliseconds() >= config[pair.first]["Cooldown"]) 
        {

        }
    }
=======
    clock.restart();
    state = BATTLE;
    sun = new Sun(config["Sun"], background_sp.getGlobalBounds());
    interval = 0;
    cards.pushback(new Card(config["PeaShooter"],background_sp.getGlobalBounds(),"PeaShooter",130, peaRect));
    cards.pushback(new Card(config["SnowPea"],background_sp.getGlobalBounds(),"SnowPea",230, snowyRect));
    cards.pushback(new Card(config["Sunflower"],background_sp.getGlobalBounds(),"Sunflower",330, sunflowerRect));
    cards.pushback(new Card(config["Walnut"],background_sp.getGlobalBounds(),"Walnut",430, peanutRect));
>>>>>>> a5db1f83683a8b71d37ff0fab6b8d18e8096fabb
}

void Battle::render(RenderWindow &window)
{
<<<<<<< HEAD

    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(background_sp);
    window.draw(pea_shooter_sp);
    window.draw(snowy_pea_sp);
    window.draw(sun_flower_sp);
    window.draw(peanut_sp);
=======
    update();
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(background_sp);
    for_each(zombies.begin(), zombies.end(), [&window](BaseZombie* zombie){ zombie->render(window); });
>>>>>>> a5db1f83683a8b71d37ff0fab6b8d18e8096fabb
    sun->render(window);
    for (auto&plant:plants)
    {
        plant->render(window);
    }
    window.display();

    
}

<<<<<<< HEAD
Battle::~Battle()
{
    delete sun;
}


void Battle::event_handler(RenderWindow& window, Event& event)
{
    if (event.type == Event::MouseButtonPressed) 
    {
        Vector2i mousePos = Mouse::getPosition(window);
        if (pea_shooter_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selected_plant = "PeaShooter";

            //cout<<"IM HERE111!"<<endl;
        } 
        else if (snowy_pea_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selected_plant = "SnowPea";
            //cout<<"IM HERE2222!"<<endl;
        } 
        else if (sun_flower_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selected_plant = "Sunflower";
            //cout<<"IM HERE3333!"<<endl;
        } 
        else if (peanut_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selected_plant = "Walnut";
            //cout<<"IM HERE44444!"<<endl;
        }
    } 
    else if (event.type == Event::MouseButtonReleased) 
    {
    
        if (is_dragging) 
        {
            Vector2i mousePos = Mouse::getPosition(window);
            if (mousePos.x >= MIN_X && mousePos.x <= WINDOW_WIDTH && 
               mousePos.y >= MIN_Y && mousePos.y <= WINDOW_HEIGHT) 
            {

                Vector2f float_pos(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                cout<<"mous pose x is:"<< float_pos.x<<"mouse pose y is :"<<float_pos.y<<endl;
                Vector2f plant_pos = find_position(selected_plant,float_pos);

                add_plant(selected_plant, plant_pos);
            }
            //cout<<"IM HERE5555!"<<endl;
            is_dragging = false;
            selected_plant = "";  
        }
    }
}

void Battle::add_plant(const string& type, const Vector2f& position) 
{
    Plant* new_plant = new Plant(config[type],type+ ".png",background_sp.getGlobalBounds(),position);
    plants.push_back(new_plant);
}

unsigned int Battle::find_nearest(const vector<unsigned int>& vec, unsigned int value,int drift) 
{
   
    unsigned int closest = vec[0]; 
    unsigned int min_difference = abs(static_cast<int>(value- drift) - static_cast<int>(vec[0])); 
    for (unsigned int element : vec) 
    {
        unsigned int difference = abs(static_cast<int>(value - drift) - static_cast<int>(element));
        if (difference <= min_difference) 
        {
            closest = element;
            min_difference = difference;
        }
    }
    return closest;
}

Vector2f Battle::find_position(const string& type,const Vector2f& position) 
{
    unsigned int grid_x = find_nearest(WIDTH_GRIDS,position.x, background_sp.getGlobalBounds().left);
    unsigned int grid_y = find_nearest(HEIGHT_GRIDS,position.y,background_sp.getGlobalBounds().top);

    cout<<"x is :"<< grid_x<<" y is:"<<grid_y<<endl;

    auto x_index = find(WIDTH_GRIDS.begin(), WIDTH_GRIDS.end(), grid_x);
    size_t x_pos = distance(WIDTH_GRIDS.begin(), x_index);

    auto y_index = find(HEIGHT_GRIDS.begin(), HEIGHT_GRIDS.end(), grid_y);
    size_t y_pos = distance(HEIGHT_GRIDS.begin(), y_index);
    int grid_num = y_pos * NUM_COLS + x_pos;
    cout<<"backx"<<background_sp.getGlobalBounds().left<<endl;
    Vector2f grid_position(static_cast<float>(grid_x+background_sp.getGlobalBounds().left) , static_cast<float>(background_sp.getGlobalBounds().top+grid_y ));
    cout<<"x"<< grid_position.x<<"y"<<grid_position.y<<endl;

    if (block_occupied.find(grid_num) == block_occupied.end()) 
    {
        return grid_position;
        block_occupied[grid_num] = true;
    }
    // else
    // {
    //     return nullopt;
    // }
}

=======
State Battle::mouse_press(int x, int y)
{
    sun->mouse_press(x, y);
    return state;
}

Battle::~Battle(){
    for_each(zombies.begin(), zombies.end(), [](BaseZombie* zombie){ delete zombie; });
    for_each(plants.begin(), plants.end(), [](Plant* plant){ delete plant; });
    delete sun;
}

void Battle::update()
{
    attack();
    find_target();
}

void Battle::find_target()
{
    auto plant_it = plants.begin();
    auto zombie_it = zombies.begin();

    while(plant_it != plants.end())
    {
        if((*plant_it)->dead())
        {
            plant_it = plants.erase(plant_it);
            continue;
        }
        while (zombie_it != zombies.end())
        {
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

void Battle::attack()
{
    if(any_of(zombies.begin(), zombies.end(),[](BaseZombie& zombie){ zombie.win(); }))
    {
        state = GAMEOVER;
        return;
    }
    else if (clock.getElapsedTime().asSeconds() >= config["Attacks"]["TotalTime"])
    {
        state = VICTORY;
        return;
    }
    unsigned int num_intervals = config["Attacks"]["TotalTime"]/config["Attacks"]["Interval"];
    float elapsed = clock.getElapsedTime().asSeconds();
    for (unsigned int i = 1; i <= num_intervals; i++){
        if ((i-1)*config["Attacks"]["Interval"] <= elapsed && i*config["Attacks"]["Interval"] > elapsed)
        {
            if(i != interval){
                interval = i;
                make_zombies();
            }
            break;
        }
    }
}

void Battle::make_zombies()
{
    unsigned int num_zombies = config["Attacks"]["StartingNum"] + (interval-1) * config["Attacks"]["IncNum"];
    unsigned int num_gargantuar = num_zombies * GARGANTUAR_RATIO;
    for (unsigned int i = 0; i < num_gargantuar; i++){
        zombies.push_back(new BaseZombie(config["Gargantuar"], "Gargantuar.png", background_sp.getGlobalBounds()));
    }
    for (unsigned int i = 0; i < (num_zombies-num_gargantuar); i++){
        zombies.push_back(new BaseZombie(config["Zombie"], "Zombie.png", background_sp.getGlobalBounds()));
    }
}
>>>>>>> a5db1f83683a8b71d37ff0fab6b8d18e8096fabb
