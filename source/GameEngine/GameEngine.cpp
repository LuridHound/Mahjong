#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include "GameEngine.h"


//
//
void GameEngine::run()
{


    int id_first = -1, id_second = -1;

    while(window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if(event.type == sf::Event::MouseButtonPressed)
            {
                //  press button and get the Rune and highlight it
                //  if pressed second time on the same rune - unhighlight it
                //  if pressed on the second rune and the type of 1-st and 2-nd rune is equal - delete them and unhighlight
                //  else unhighlight them.
                //

                if(id_first == -1)
                {
                    int x = sf::Mouse::getPosition().x;
                    int y = sf::Mouse::getPosition().y;
                    id_first = geometry.getRuneID(x, y);
                }
                else
                {
                    int x = sf::Mouse::getPosition().x;
                    int y = sf::Mouse::getPosition().y;
                    id_second = geometry.getRuneID(x, y);
                    if(id_first == id_second || id_second == -1)
                    {
                        id_first = -1;
                        break;
                    }
                    if(geometry.isFree(id_first, id_second))
                        geometry.deleteById(id_first, id_second);
                    id_first = -1;
                }
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
    window = new sf::RenderWindow(sf::VideoMode(1920, 1080), title, sf::Style::Fullscreen);

    backgroundManager.changeBackground();
    geometry.loadLevel();
}