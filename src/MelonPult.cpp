#include "MelonPult.hpp"

MelonPult::MelonPult(map<string, float> config, string melon_path, const Vector2f &position, FloatRect bg_bound) : Plant(config, "MelonPult.png", position), bg_bound(bg_bound)
{
    plant_sp.setTextureRect(MELONPULT_RECT);
    if (!melon_tex.loadFromFile(IMAGES_PATH + melon_path))
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    melon.setTexture(melon_tex);
    melon.setTextureRect(IntRect(690, 180, 65, 55));
    melon.setPosition(plant_sp.getGlobalBounds().left + 2, plant_sp.getGlobalBounds().height + 5);
    attack_clock.restart();
    zombie = nullptr;
}

void MelonPult::update()
{

    if (attack_clock.getElapsedTime().asSeconds() >= config["HitRate"] && zombie != nullptr)
    {
        melons.push_back(make_pair(melon, clac_trajectory(melon.getGlobalBounds().left, zombie->get_width())));
        attack_clock.restart();
    }
    if (!melons.empty())
    {
        auto melon_it = melons.begin();
        while (melon_it != melons.end())
        {
            melon_it->first.move(Vector2f(config["Speed"], melon_it->second.front()));
            melon_it->second.pop_front();
            zombie->hurt(config["Damage"]);
            if (zombie->dead())
                zombie = nullptr;
            if (melon_it->second.empty())
            {
                melon_it = melons.erase(melon_it);
            }
            else
                ++melon_it;
        }
    }
}

void MelonPult::set_target(BaseZombie *z)
{
    if (z->get_height() == plant_sp.getGlobalBounds().height)
    {
        if (zombie == nullptr ||
            (z->get_width() >= plant_sp.getGlobalBounds().left && z->get_width() < zombie->get_width()))
            zombie = z;
    }
}

list<float> MelonPult::clac_trajectory(int start_p, int start_z)
{
    int collision_time = (start_z - start_p) / (config["Speed"] + zombie->get_speed());
    list<float> trajectory = {0};
    int collision_width = start_p + config["Speed"] * collision_time;
    for (int i = 0; i < collision_time; i++)
    {
        float x = start_p + i * config["Speed"];
        float relative_offset = (CURVE_COEFF * (x - start_p) * (x - collision_width)) - trajectory.back();
        trajectory.push_back(relative_offset);
    }
    trajectory.pop_front();
    return trajectory;
}

void MelonPult::render(RenderWindow &window)
{
    update();
    window.draw(plant_sp);
    for_each(melons.begin(), melons.end(), [&window](pair<Sprite, list<float>> melon)
             { window.draw(melon.first); });
}