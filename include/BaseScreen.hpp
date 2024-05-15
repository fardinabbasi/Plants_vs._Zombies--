#ifndef BASESCREEN_HPP
#define BASESCREEN_HPP

#include "Defs.hpp"


class BaseScreen{
    public:
    BaseScreen(){};
    BaseScreen(const string bg_image_path, const string bg_music_path);
    State render(RenderWindow &window);
    
    protected:
    State state;
    Texture background_tex;
    Sprite background_sp;
    Music music;
    bool music_played;
};

#endif