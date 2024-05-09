#include "BaseScreen.hpp"

BaseScreen::BaseScreen(const string bg_image_path, const string bg_music_path){
    if (!background_tex.loadFromFile(IMAGES_PATH + bg_image_path)) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    if (!music.openFromFile(MUSIC_PATH + bg_music_path))
        cerr << FILE_FAILED_MESSAGE << endl;
    music.setLoop(true);
    background_sp.setTexture(background_tex);
    Vector2f sprite_size(background_sp.getTextureRect().width, background_sp.getTextureRect().height);
    Vector2f centeredPosition(
        WINDOW_WIDTH / 2.f - sprite_size.x / 2.f,
        WINDOW_HEIGHT / 2.f - sprite_size.y / 2.f);
    background_sp.setPosition(centeredPosition);
}

void BaseScreen::render(RenderWindow &window){
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(background_sp);
    window.display();
}