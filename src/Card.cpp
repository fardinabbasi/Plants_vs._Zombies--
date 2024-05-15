#include "Card.hpp"

Card::Card(map<string, float> config, Vector2f pos, const string tex_path):
config(config)
{
    IntRect sub_rect;
    if (!card_tex.loadFromFile(IMAGES_PATH + tex_path)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if (!font.loadFromFile(FONTS_PATH + "score.ttf")) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    type = tex_path.substr(0, tex_path.find(".png"));
    if(type == "PeaShooter")
        sub_rect = PEA_RECT;
    else if(type == "SnowPea")
        sub_rect = SNOWPEA_RECT;
    else if (type == "Sunflower")
        sub_rect = SUNFLOWER_RECT;
    else if (type == "Walnut")
        sub_rect = WALNUT_RECT;
    else if (type == "MelonPult")
        //sub_rect = MELONPULT_RECT;

    card_sp.setTexture(card_tex);
    card_sp.setTextureRect(sub_rect);
    card_sp.setScale(0.25f, 0.25f);
    card_sp.setPosition(pos);

    price_txt.setFont(font);
    price_txt.setFillColor(Color::Black);
    price_txt.setCharacterSize(16);
    price_txt.setPosition(Vector2f(pos.x + 50, pos.y-10));

    time_txt.setFont(font);
    time_txt.setFillColor(Color::Black);
    time_txt.setCharacterSize(16);
    time_txt.setPosition(Vector2f(Vector2f(pos.x + 50, pos.y+10)));
    cool_down.restart();
    
}

void Card::render(RenderWindow &window)
{
    price_txt.setString(to_string(config["Price"]));
    time_txt.setString(to_string(config["Cooldown"]-cool_down.getElapsedTime().asSeconds()) + "s");
    window.draw(card_sp);
    window.draw(price_txt);
}

bool Card::contains(int x, int y)
{
    return card_sp.getGlobalBounds().contains(x,y);
}

plant* Card::make_plant(Vector2f& position)
{
    cool_down.restart();
    if (type == "peaShooter")
    {
        return new PeaShooter(config["peaShooter"],"Projectiles",position);

    }
    else if (type == "SnowPea")
    {
        return new SnowPea(config["SnowPea"],"Projectiles",position);
    }
    else if (type == "Sunflower")
    {
        return new SunFlower(config["Sunflower"],"Projectiles",position);
    }
    else if (type == "Walnut")
    {
        return new Plant("Walnut",position);
    }
}

float Card::get_price()
{
    return config["Price"];
}

bool Card::ready()
{
    return config["Cooldown"] <= cool_down.getElapsedTime().asSeconds();
}