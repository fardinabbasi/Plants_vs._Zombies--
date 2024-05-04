#include "PVZ.hpp"


PVZ::PVZ(map<string, map<string, int>> config): config(config)
{
    window.create(VideoMode(WINDOW_WIDTH ,WINDOW_HEIGHT), "PVZ", Style::Close);
    window.setFramerateLimit(FRAME_RATE);
    state = Starting_Screen;
    Menu menu;
}

void PVZ::run(){
    while (window.isOpen()) {
        window.clear(Color::Black);
        event_handler();
        switch (state)
        {
        case Starting_Screen:
            menu.render(window);
            break;
        case IN_GAME:
            break;
        case VICTORY_SCREEN:
            break;
        case GAMEOVER_SCREEN:
            break;
        case EXIT:
            window.close();
            break;
        default:
            break;
        }
    }
}

void PVZ::event_handler(){
    Event event;
    while (window.pollEvent(event) && state != EXIT) {
    switch (event.type) {
    case (Event::Closed):
      state = EXIT;
      break;
    default:
      break;
    }
  }
}