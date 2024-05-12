#include "Battle.hpp"
unsigned int find_nearest(const vector<unsigned int>& vec, unsigned int value) 
{
   
    unsigned int closest = vec[0]; 
    unsigned int min_difference = abs(static_cast<int>(value) - static_cast<int>(vec[0])); 
    for (unsigned int element : vec) 
    {
        unsigned int difference = abs(static_cast<int>(value) - static_cast<int>(element));
        if (difference < min_difference) 
        {
            closest = element;
            min_difference = difference;
        }
    }
    return closest;
}
Battle::Battle(map<string, map<string, int>>& config): 
config(config), BaseScreen("Background.png", "Loonboon.ogg")
{
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
 
}

void Battle::render(RenderWindow &window)
{
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(background_sp);
    window.draw(pea_shooter_sp);
    window.draw(snowy_pea_sp);
    window.draw(sun_flower_sp);
    window.draw(peanut_sp);
    sun->render(window);
    for (auto&plant:plants)
    {
        plant->render(window);
    }
    window.display();
    
}

Battle::~Battle(){
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
            selected_plant = "pea_shooter";
            //cout<<"IM HERE111!"<<endl;
        } 
        else if (snowy_pea_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selected_plant = "snow_shooter";
            //cout<<"IM HERE2222!"<<endl;
        } 
        else if (sun_flower_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selected_plant = "sun_flower";
            //cout<<"IM HERE3333!"<<endl;
        } 
        else if (peanut_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selected_plant = "peanut";
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

                Vector2f world_pos = window.mapPixelToCoords(mousePos);
                Vector2f plant_pos = find_position(selected_plant,world_pos);

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
    Plant* new_plant = new Plant(config["PeaShooter"],"PeaShooter.png",background_sp.getGlobalBounds(),position);
    plants.push_back(new_plant);
    block_occupied[position] = new_plant;
}

Vector2f Battle::find_position(const string& type,const Vector2f& position) 
{
    unsigned int grid_x = find_nearest(WIDTH_GRIDS,position.x);
    unsigned int grid_y = find_nearest(HEIGHT_GRIDS,position.y);
    Vector2i grid_position(grid_x + background_sp.getGlobalBounds().left , grid_y + background_sp.getGlobalBounds().top);
    if (block_occupied.find(grid_position) == block_occupied.end()) 
    {
        return grid_position;
    }
}

