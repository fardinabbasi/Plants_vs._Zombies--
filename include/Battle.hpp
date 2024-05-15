#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <algorithm>
#include <list>
#include <limits>
#include <math.h>
#include "BaseZombie.hpp"
#include "Defs.hpp"
#include "BaseScreen.hpp"
#include "Sun.hpp"
#include "Card.hpp"
#include "Plant.hpp"

class Battle : public BaseScreen
{
public:
    Battle(map<string, map<string, float>> &config);
    ~Battle();
    void render(RenderWindow &window);
    State mouse_press(int x, int y);
    void update();
    void find_target();
    void attack();
    void make_zombies();

private:
    map<string, map<string, float>> config;
    Sun *sun;
    list<Plant *> plants;
    list<Card*> deck;
    Sprite pea_shooter_sp;
    Texture pea_shooter_tex;
    bool is_dragging;
    // map<int, bool> block_occupied;
    string selected_plant;
    Sprite snowy_pea_sp;
    Texture snowy_pea_tex;

    Sprite sun_flower_sp;
    Texture sun_flower_tex;

    Sprite peanut_sp;
    Texture peanut_tex;

    list<BaseZombie *> zombies;
    State state;
    Clock attack_clk;
    unsigned int interval;
};

#endif
