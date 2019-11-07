#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include "GameEngine.h"


//
//
void GameEngine::run()
{


    while(window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if(event.type == sf::Event::MouseButtonPressed)
            {

            }

        }
        window->clear();

        backgroundManager.draw(window);
        geometry.draw(window);

        window->display();
    }
}


//
//
GameEngine::GameEngine()
{
    window = new sf::RenderWindow(sf::VideoMode(1920, 1080), title);

    backgroundManager.changeBackground();
}