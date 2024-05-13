#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "Defs.hpp"
#include "BaseScreen.hpp"
#include "Sun.hpp"
#include "Plant.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <optional>

class Battle: public BaseScreen
{
    public:
    Battle(map<string, map<string, int>>& config);
    ~Battle();
    void render(RenderWindow& window);//will override
    void event_handler(RenderWindow& window, Event& event);
    void add_plant(const string& type, const Vector2f& position);
    Vector2f find_position(const string& type,const Vector2f& position);
    unsigned int find_nearest(const vector<unsigned int>& vec, unsigned int value,int drift);

    
    private:
    map<string, map<string, int>> config;
    map<string ,Time> cool_down_time;
    map<string ,Clock> cool_downs;
    Sun* sun;
    list<Plant*> plants;
    Sprite pea_shooter_sp;
    Texture pea_shooter_tex;
    bool is_dragging;
    map<int, bool> block_occupied;
    string selected_plant;
    Sprite snowy_pea_sp;
    Texture snowy_pea_tex;
    
    Sprite sun_flower_sp;
    Texture sun_flower_tex;
    
    Sprite peanut_sp;
    Texture peanut_tex;
    
    
    
};

#endif
