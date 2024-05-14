#ifndef BASESCREEN_HPP
#define BASESCREEN_HPP

#include "Defs.hpp"


class BaseScreen{
    public:
    BaseScreen(){};
    BaseScreen(const string bg_image_path, const string bg_music_path);
    void render(RenderWindow &window);
    
    protected:
    Texture background_tex;
    Sprite background_sp;
    Music music;
};

#endif