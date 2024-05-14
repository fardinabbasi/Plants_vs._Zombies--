#include "Card.hpp"
Card::Card(map<string, int> config,FloatRect bg_bound,string type,int y_ofset, IntRect subrect)
{
    this->config = config;
    this->type = type;
    this-> can_plant = false;
    if (!deck_tex.loadFromFile(IMAGES_PATH + type)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if (!font.loadFromFile(FONTS_PATH + "score.ttf")) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    deck_sp.setTexture(deck_tex);
    deck_sp.setTextureRect(subrect);
    deck_sp.setOrigin(static_cast<Vector2f>(deck_tex.getSize()) / 2.f);
    deck_sp.setScale(0.25f, 0.25f);
    deck_sp.setPosition(Vector2f(bg_bound.left + 70.f, bg_bound.top + static_cast<float>(y_offset)));
    deck_txt.setFont(font);
    deck_txt.setFillColor(Color::Black);
    deck_txt.setCharacterSize(16);
    deck_txt.setPosition(Vector2f(bg_bound.left + 170.f, bg_bound.top + static_cast<float>(y_offset)));
    cool_down.restart();
    
}

void Card::render(RenderWindow &window)
{
    update();
    window.draw(deck_sp);
    window.draw(deck_txt);
}

void Card::update()
{
    int remaining_time = (config[type]["Cooldown"]*1000 - cool_down.getElapsedTime().asMilliseconds())/1000;

    if (remaining_time <= 0) 
    {
        remaining_time = 0;
        can_plant = true;
    }

    deck_txt.setString(to_string(remaining_time) + "s")
}

bool Card::ready()
{
    return can_plant;
}

Card::reset()
{
    cool_down.restart();
}

string Card::get_name()
{
    return type;
}

bool Card::contains(int x, int y)
{
    FloatRect bounds = deck_sp.getGlobalBounds();
    return bounds.contains(static_cast<float>(x), static_cast<float>(y));
}