#include "PVZ.hpp"


PVZ::PVZ(map<string, map<string, int>> config):
battle(config), victory_screen("Victory.jpg", "Victory.ogg"), lose_screen("GameOver.png", "Lose.ogg")
{
    window.create(VideoMode(WINDOW_WIDTH ,WINDOW_HEIGHT), "PVZ", Style::Close);
    window.setFramerateLimit(FRAME_RATE);
    state = Starting;
}

void PVZ::run(){
    while (window.isOpen()) {
        window.clear(Color::Black);
        event_handler();
        switch (state)
        {
        case Starting:
            menu.render(window);
            break;
        case BATTLE:
            battle.render(window);
            break;
        case VICTORY:
            victory_screen.render(window);
            break;
        case GAMEOVER:
            lose_screen.render(window);
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
    while (window.pollEvent(event) && state != EXIT) 
    {
        if(event.type == Event::Closed)
            state = EXIT;
        else if((event.type == Event::MouseButtonPressed || event.type == Event::MouseButtonReleased) && event.mouseButton.button == Mouse::Left)
        {
            switch (state)
            {
            case Starting:
                if(menu.start_button(Mouse::getPosition(window)))
                    state = BATTLE;
                break;
            case BATTLE:
                // cout<<"IM HERE!"<<endl;
                battle.event_handler(window, event);
                break;
            default:
                break;
            }
        }
    }
}