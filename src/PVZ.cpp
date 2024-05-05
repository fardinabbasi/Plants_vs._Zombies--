#include "PVZ.hpp"


PVZ::PVZ(map<string, map<string, int>> config): battle(config)
{
    window.create(VideoMode(WINDOW_WIDTH ,WINDOW_HEIGHT), "PVZ", Style::Close);
    window.setFramerateLimit(FRAME_RATE);
    state = Starting_Screen;
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
        case BATTLE:
            battle.render(window);
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
        if(event.type == Event::Closed)
            state = EXIT;
        else if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
            switch (state)
            {
            case Starting_Screen:
                if(menu.start_button(Mouse::getPosition(window)))
                    state = BATTLE;
                break;
            case BATTLE:
                break;
            default:
                break;
            }
        }

    }
}