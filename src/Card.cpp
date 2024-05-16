#include "Card.hpp"

Card::Card(map<string, float>& config, FloatRect bg_bound, const string tex_path):
config(config), bg_bound(bg_bound)
{
    if (!card_tex.loadFromFile(IMAGES_PATH + tex_path)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if (!font.loadFromFile(FONTS_PATH + "score.ttf")) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    IntRect sub_rect;
    Vector2f pos;

    type = tex_path.substr(0, tex_path.find(".png"));
    if(type == "PeaShooter")
    {
        sub_rect = PEA_RECT;
        pos = Vector2f(bg_bound.left+90, bg_bound.top+130);

    }
    else if(type == "SnowPea")
    {    
        sub_rect = SNOWPEA_RECT;
        pos = Vector2f(bg_bound.left+90,bg_bound.top+230);
    }
    else if (type == "Sunflower")
    {
        sub_rect = SUNFLOWER_RECT;
        pos = Vector2f(bg_bound.left+90, bg_bound.top+330);
    }
    else if (type == "Walnut")
    {
        sub_rect = WALNUT_RECT;
        pos = Vector2f (bg_bound.left+90, bg_bound.top+430);
    }
    /*else if (type == "MelonPult")
    {
        sub_rect = MELONPULT_RECT;
        pos = Vector2f(bg_bound.left+70, bg_bound.top+530 );
    }*/
    else{
        cerr << WRONG_TYPE_MESSAGE << endl;
    }

    card_sp.setTexture(card_tex);
    card_sp.setTextureRect(sub_rect);
    card_sp.setPosition(pos);
    card_sp.setScale(0.5f, 0.5f);

    price_txt.setFont(font);
    price_txt.setFillColor(Color::Black);
    price_txt.setPosition(Vector2f(pos.x + 65, pos.y+10));
    price_txt.setString(to_string(int(config["Price"])));
    price_txt.setScale(0.5, 0.5);

    time_txt.setFont(font);
    time_txt.setFillColor(Color::Black);
    time_txt.setPosition(Vector2f(Vector2f(pos.x + 65, pos.y+30)));
    time_txt.setScale(0.5, 0.5);

    cool_down.restart();
    
}

void Card::render(RenderWindow &window){
    
    time_txt.setString(to_string(calc_cooldown()) + "(s)");
    window.draw(price_txt);
    window.draw(time_txt);
    window.draw(card_sp);
}

int Card::calc_cooldown(){
    int remaining_cooldown = config["Cooldown"] - cool_down.getElapsedTime().asSeconds();
    if (remaining_cooldown <= 0)
        return 0;
    else
        return remaining_cooldown;
}

bool Card::contains(int x, int y){
    return card_sp.getGlobalBounds().contains(x,y);
}

Plant* Card::make_plant(Vector2f& position)
{
    cool_down.restart();
    if (type == "peaShooter"){
        return new PeaShooter(config,"Projectiles.png", position, bg_bound);
    }
    else if (type == "SnowPea"){
        return new SnowPea(config,"Projectiles.png", position, bg_bound);
    }
    else if (type == "Sunflower"){
        return new Sunflower(config, "Projectiles.png", position);
    }
    else if (type == "Walnut"){
        return new Plant(config, "Walnut.png", position);
    }
    else{
        return nullptr;
    }
}

float Card::get_price(){
    return config["Price"];
}

bool Card::ready(){
    return calc_cooldown() <= 0;
}