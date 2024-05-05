#ifndef BASESCREEN_HPP
#define BASESCREEN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Defs.hpp"
#include "iostream"

using namespace std;
using namespace sf;

class BaseScreen{
public:
BaseScreen(){};
BaseScreen(const string bg_image_path, const string bg_music_path);
void render(RenderWindow &window);
protected:
Texture background_tx;
Sprite background_sp;
Music music;
};

#endif