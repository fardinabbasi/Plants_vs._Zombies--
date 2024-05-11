#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "Defs.hpp"
#include "BaseScreen.hpp"
#include "Sun.hpp"
#include "Plant.hpp"

struct GridInfo 
{
    Vector2f plant_position;
    Vector2i grid_position;
};

class Battle: public BaseScreen
{
    public:
    Battle(map<string, map<string, int>>& config);
    ~Battle();
    void render(RenderWindow& window);//will override
    void event_handler(RenderWindow& window, Event& event);
    void add_plant(const string& type, const GridInfo& position);
    GridInfo find_position(const string& type,const Vector2f& position);
    
    private:
    map<string, map<string, int>> config;
    Sun* sun;
    list<Plant*> plants;
    Sprite pea_shooter_sp;
    Texture pea_shooter_tex;
    bool is_dragging;
    map<Vector2i, Plant*> block_occupied;
    string selected_plant;
    Sprite snowy_pea_sp;
    Texture snowy_pea_tex;
    
    Sprite sun_flower_sp;
    Texture sun_flower_tex;
    
    Sprite peanut_sp;
    Texture peanut_tex;
    
    
    
};

#endif
