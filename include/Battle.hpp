#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <algorithm>
#include <list>
#include "BaseZombie.hpp"
#include "Defs.hpp"
#include "BaseScreen.hpp"
#include "Sun.hpp"
<<<<<<< HEAD
#include "Plant.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <optional>
=======
#include "Card.hpp"

>>>>>>> a5db1f83683a8b71d37ff0fab6b8d18e8096fabb

class Battle: public BaseScreen
{
    public:
    Battle(map<string, map<string, int>>& config);
    ~Battle();
<<<<<<< HEAD
    void render(RenderWindow& window);//will override
    void event_handler(RenderWindow& window, Event& event);
    void add_plant(const string& type, const Vector2f& position);
    Vector2f find_position(const string& type,const Vector2f& position);
    unsigned int find_nearest(const vector<unsigned int>& vec, unsigned int value,int drift);

=======
    void render(RenderWindow& window);
    State mouse_press(int x, int y);
    void update();
    void find_target();
    void attack();
    void make_zombies();
>>>>>>> a5db1f83683a8b71d37ff0fab6b8d18e8096fabb
    
    private:
    map<string, map<string, int>> config;
    map<string ,Time> cool_down_time;
    map<string ,Clock> cool_downs;
    Sun* sun;
<<<<<<< HEAD
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
    
    
    
=======
    list<BaseZombie*> zombies;
    list<Plant*> plants;
    list <Card*> cards;
    State state;
    Clock clock;
    unsigned int interval;
>>>>>>> a5db1f83683a8b71d37ff0fab6b8d18e8096fabb
};

#endif
