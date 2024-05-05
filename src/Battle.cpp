#include "../include/Battle.hpp"

Battle::Battle(map<string, map<string, int>>& config): config(config){
    if (!background_tx.loadFromFile(IMAGES_PATH + "Background.png")) {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    background_sp.setTexture(background_tx);
    if (!music.openFromFile(MUSIC_PATH + "Loonboon.ogg"))
        cerr << FILE_FAILED_MESSAGE << endl;
    music.setLoop(true);
}

void Battle::render(RenderWindow &window){
    if(music.getStatus() != Music::Playing)
        music.play();
    window.draw(background_sp);
    window.display();
}