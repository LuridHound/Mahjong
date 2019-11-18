#include <SFML/Window/Event.hpp>

#include "GameEngine.h"


//
//
GameEngine::GameEngine():
        stage(Enums::Stage::MENU), user(), backgroundManager(), eventManager()
{
    initializeWindow();

    backgroundManager.changeBackground(Enums::Background::Background::MENU);

    eventManager.subscribe(&user);

    tempLevel = user.levelChoice();
}


//
//
void GameEngine::run()
{
    window.setFramerateLimit(60);

    while ( window.isOpen() )
    {
        sf::Event event;
        while ( window.pollEvent(event) )
        {
            if ( event.type == sf::Event::Closed )
            {
                window.close();
            }

            if ( stage == Enums::Stage::MENU )
            {
                if ( event.type == sf::Event::KeyPressed )
                {
                    if ( event.key.code == sf::Keyboard::Escape )
                    {
                        window.close();
                    }
                }
            }

            eventManager.pushEvent(&event);

            user.update(stage, geometry);
        }

        if ( user.levelChoice() != tempLevel )
        {
            tempLevel = user.levelChoice();
            backgroundManager.changeBackground(static_cast<Enums::Background::Background>(static_cast<int>(tempLevel)));
            user.clear();
            if ( stage != Enums::Stage::MENU )
            {
                geometry.loadLevel(static_cast<int>(tempLevel));
            }
        }

        window.clear();

        backgroundManager.draw(window, stage);

        if ( stage == Enums::Stage::GAME )
        {
            geometry.draw(window, stage, backgroundManager);
        }

        window.display();

    }

    return;
}


//
//
void GameEngine::initializeWindow()
{
    sf::Image icon;
    icon.loadFromFile("resources/Textures/Runes/0.png");

    sf::VideoMode videoMode(sf::VideoMode().getDesktopMode());

    window.create(videoMode, title, sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    return;
}