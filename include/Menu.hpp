#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Defs.hpp"

using namespace sf;
using namespace std;

class Menu{
public:
Menu();
void render(RenderWindow &window);
private:
Texture texture;
Sprite sprite;
Music music;
};

#endif