#include "Menu.hpp"

Menu::Menu(){
    if (!texture.loadFromFile(IMAGES_PATH + "StartingScreen.png")) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    sprite.setTexture(texture);
    if (!music.openFromFile(MUSIC_PATH + "StartingScreen.ogg"))
        cerr << FILE_FAILED_MESSAGE << endl;
    music.setLoop(true);
    button.setPosition(250, 550);
    button.setSize(Vector2f(610, 75));
}

void Menu::render(RenderWindow &window){
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(sprite);
    window.display();
}

bool Menu::start_button(Vector2i mousePos){
    FloatRect buttonBounds = button.getGlobalBounds();
    if(buttonBounds.contains(static_cast<Vector2f>(mousePos))){
        music.stop();
        return true;
    }
    else
        return false;
}