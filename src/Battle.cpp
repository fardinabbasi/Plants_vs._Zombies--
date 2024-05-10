#include "Battle.hpp"
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
    window.display();
}

Battle::~Battle(){
    delete sun;
}


void Battle::handleEvents(RenderWindow& window, Event& event)
{
    if (event.type == Event::MouseButtonPressed) 
    {
        Vector2i mousePos = Mouse::getPosition(window);
        if (pea_shooter_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selectedPlant = &pea_shooter_sp;
        } 
        else if (snowy_pea_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selectedPlant = &snowy_pea_sp;
        } 
        else if (sun_flower_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selectedPlant = &sun_flower_sp;
        } 
        else if (peanut_sp.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
        {
            is_dragging = true;
            selectedPlant = &peanut_sp;
        }
    } 
    else if (event.type == Event::MouseButtonReleased) 
    {
        is_dragging = false;
        selectedPlant = nullptr;
    } 
    else if (event.type == Event::MouseMoved) 
    {
        if (is_dragging && selectedPlant != nullptr) 
        {
            Vector2i mousePos = Mouse::getPosition(window);
            selectedPlant->setPosition(mousePos.x - selectedPlant->getGlobalBounds().width / 2,
                                       mousePos.y - selectedPlant->getGlobalBounds().height / 2);
        }
    }
}
