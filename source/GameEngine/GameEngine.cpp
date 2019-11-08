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
                int x = sf::Mouse::getPosition().x;
                int y = sf::Mouse::getPosition().y;

                if(first == nullptr)
                {
                    first = geometry.getRune(x, y);
                    if ( first != nullptr )
                    {
                        std::cout << first->getID();
                        first->highlight();
                    }
                }
                else
                {
                    second = geometry.getRune(x, y);
                    if ( second == nullptr)
                    {
                        break;
                    }
                    if ( first == second )
                    {
                        first->unhighlight();
                        first = second = nullptr;
                    }

                    if ( second == nullptr )
                    {
                        break;
                    }

                    first->unhighlight();
                    second->unhighlight();

                    std::cout << "COMPARE";
                    std::cout << first->getType() << ' ' << second->getType() << '\n';

                    if ( first->getType() == second->getType() )
                    geometry.deleteRunes(first, second);
                    first = nullptr;
                    second = nullptr;
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