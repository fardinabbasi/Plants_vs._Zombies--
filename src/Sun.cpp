#include "../include/Sun.hpp"

Sun::Sun(map<string, int> config, const FloatRect bg_bound):
config(config), bg_bound(bg_bound), gen(SEED)
{
    if(config.contains("StartingNum"))
        sun_budget = config["StartingNum"];
    else
        sun_budget = 0;
    if (!sun_tex.loadFromFile(IMAGES_PATH + "Sun.png")) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if (!font.loadFromFile(FONTS_PATH + "score.ttf")) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }

    IntRect subrect(0, 0, 350, 325);
    deck_sp.setTexture(sun_tex);
    deck_sp.setTextureRect(subrect);
    deck_sp.setPosition(bg_bound.left+70, bg_bound.top+30);
    deck_sp.setScale(0.25, 0.25);
    
    deck_txt.setFont(font);
    deck_txt.setString(to_string(sun_budget));
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
    for_each(suns.begin(), suns.end(), [](Sprite& sun){ sun.move(0,1); });
    if (suns.front().getPosition().y >= bg_bound.height)
        suns.pop_front();

    if(clock.getElapsedTime().asSeconds() >= config["Interval"]){
        clock.restart();
        uniform_int_distribution<int> dis(260, 980);
        Sprite new_sun = deck_sp;
        new_sun.setPosition(Vector2f(dis(gen), 0));
        suns.push_back(new_sun);
    }
}