#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "GameEngine.h"


//
//
[[nodiscard]]
bool isOneType(Rune* first, Rune* second)
{
    if ( first->getType() == second->getType() )
    {
        return true;
    }

    return false;
}


//
//
void GameEngine::run()
{

    Rune* first = nullptr, *second = nullptr;

    window->setFramerateLimit(60);
    while ( window->isOpen() )
    {
        sf::Event event;
        while ( window->pollEvent(event) )
        {
            if ( event.type == sf::Event::Closed )
            {
                window->close();
            }

            if(stage == Enums::Stage::MENU)
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                }
            }

            eventManager->pushEvent(&event);

            user->update(stage, &geometry);
        }

        if ( user->levelChoice() != tempLevel )
        {
            tempLevel = user->levelChoice();
            backgroundManager->changeBackground(static_cast<Enums::Background::Background>(static_cast<int>(tempLevel)));
            user->clear();
            geometry.clear();
            if ( stage != Enums::Stage::MENU )
            {
                geometry.loadLevel(static_cast<int>(tempLevel));
            }
        }

        window->clear();

        backgroundManager->draw(window, stage);

        if(stage == Enums::Stage::GAME)
        {
            geometry.draw(window, stage, backgroundManager);
        }

        window->display();

    }

    return;
}


//
//
GameEngine::GameEngine():
stage(Enums::Stage::MENU)
{
    user = new User();
    initializeWindow();

    tempLevel = user->levelChoice();
    backgroundManager = new BackgroundManager();

    eventManager = new EventManager();
    eventManager->subscribe(user);

    backgroundManager->changeBackground(Enums::Background::Background::MENU);
    geometry.loadLevel(2);
}


//
//
void GameEngine::initializeWindow()
{

    sf::Image icon;
    icon.loadFromFile("resources/Textures/Runes/0.png");

    sf::VideoMode videoMode(sf::VideoMode().getDesktopMode());

    window = new sf::RenderWindow(videoMode, title, sf::Style::Fullscreen);

    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    return;
}