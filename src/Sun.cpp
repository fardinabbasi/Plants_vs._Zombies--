#include "Sun.hpp"

Sun::Sun(map<string, float> config, const FloatRect bg_bound):
config(config), bg_bound(bg_bound)
{

    budget = config["StartingNum"];

    if (!sun_tex.loadFromFile(IMAGES_PATH + "Sun.png")) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if (!font.loadFromFile(FONTS_PATH + "score.ttf")) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    deck_sp.setTexture(sun_tex);
    deck_sp.setTextureRect(SUN_RECT);
    deck_sp.setPosition(bg_bound.left+70, bg_bound.top+30);
    deck_sp.setScale(0.25, 0.25);
    
    deck_txt.setFont(font);
    deck_txt.setString(to_string(budget));
    deck_txt.setFillColor(Color::Black);
    deck_txt.setPosition(Vector2f(bg_bound.left+170, bg_bound.top+50));
    
    clock.restart();
}

void Sun::render(RenderWindow &window){
    update();
    window.draw(deck_sp);
    for (auto&sun:suns){
        window.draw(sun);
    }
    window.draw(deck_txt);
}

void Sun::update(){
    float speed = config["Speed"];
    for_each(suns.begin(), suns.end(), [speed](Sprite& sun){ sun.move(0, speed); });
    if (suns.front().getPosition().y >= bg_bound.height)
        suns.pop_front();

    if(clock.getElapsedTime().asSeconds() >= config["Interval"]){
        clock.restart();
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(BATTLE_FIELD.left, BATTLE_FIELD.left + BATTLE_FIELD.width);
        Sprite new_sun = deck_sp;
        new_sun.setPosition(Vector2f(dis(gen), 0));
        suns.push_back(new_sun);
    }
    deck_txt.setString(to_string(budget));
}

bool Sun::mouse_press(int x, int y){
    auto it = suns.begin();
    while(it != suns.end()){
        if (it->getGlobalBounds().contains(Vector2f(x,y))){
            budget++;
            it = suns.erase(it);
            return true;
        }
        else
            ++it;
    }
    return false;
}

bool Sun::can_buy(float price){
    return budget >= price;
}