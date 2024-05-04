#include "Menu.hpp"

Menu::Menu(){
    if (!texture.loadFromFile(IMAGES_PATH + "StartingScreen.png")) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    sprite.setTexture(texture);
    if (!music.openFromFile(MUSIC_PATH + "StartingScreen.ogg"))
        cerr << FILE_FAILED_MESSAGE << endl;
    music.setLoop(true);
}

void Menu::render(RenderWindow &window){
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(sprite);
    window.display();
}