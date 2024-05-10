#include "Plant.hpp"

Plant::Plant(map<string, int> config,string plant_tex_file,const FloatRect bg_bound)
{
    this-> damage = config['damage'];
    this-> health = config['health'];
    this-> hit_rate = config['hit_rate'];
    this-> speed = config['speed'];
    this-> cool_down = config['cool_down'];
    this-> price = config['price'];
    if (!plant_tex.loadFromFile(IMAGES_PATH + string plant_tex_file)) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if (!font.loadFromFile(FONTS_PATH + "score.ttf")) 
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    IntRect subrect(0, 0, 350, 325);
    deck_sp.setTexture(plant_tex);
    deck_sp.setTextureRect(subrect);
    deck_sp.setPosition(bg_bound.left+70, bg_bound.top+30);//later change
    deck_sp.setScale(0.25, 0.25);
    deck_txt.setFont(font);

    plant_sp.setTexture(plant_tex);
    plant_sp.setTextureRect(subrect);
    plant_sp.setScale(0.25, 0.25);

    //deck_txt.setString(to_string(sun_budget));
    deck_txt.setFillColor(Color::Black);
    deck_txt.setPosition(Vector2f(bg_bound.left+170, bg_bound.top+50));//later change
    clock.restart();

}