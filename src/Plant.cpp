#include "Plant.hpp"

Plant::Plant(map<string, int> config,string plant_tex_file,const FloatRect bg_bound,const Vector2f& position)
{
    this-> position = position;
    this-> damage = config["damage"];
    this-> health = config["health"];
    this-> hit_rate = config["hit_rat"];
    this-> speed = static_cast<float>(config["speed"]);
    this-> cool_down = milliseconds(config["cool_down"]);
    this-> price = config["price"];
    if (!plant_tex.loadFromFile(IMAGES_PATH + plant_tex_file)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if (!font.loadFromFile(FONTS_PATH + "score.ttf")) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    IntRect subrect(0, 0, 350, 325);
    // deck_sp.setTexture(plant_tex);
    // deck_sp.setTextureRect(subrect);
    // deck_sp.setPosition(bg_bound.left+70, bg_bound.top+30);//later change
    // deck_sp.setScale(0.25, 0.25);
    // deck_txt.setFont(font);

    plant_sp.setTexture(plant_tex);
    plant_sp.setTextureRect(subrect);
    plant_sp.setScale(0.25, 0.25);
    plant_sp.setPosition(position);

    //deck_txt.setString(to_string(sun_budget));
    //deck_txt.setFillColor(Color::Black);
    //deck_txt.setPosition(Vector2f(bg_bound.left+170, bg_bound.top+50));//later change

}

void Plant::render(RenderWindow &window)
{
    //update();
    //window.draw(deck_sp);
    // for (auto&sun:suns){
    //     window.draw(sun);
    // }
    window.draw(plant_sp);
}