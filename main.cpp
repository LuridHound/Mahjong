#include <SFML/Graphics.hpp>
#include "source/BackgroundManager/BackgroundManager.h"


int main()
{
    const char* title = "Mahjong";
    sf::RenderWindow window(sf::VideoMode(1920, 1080), title);

    BackgroundManager backgroundManager;
    backgroundManager.changeBackground();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        backgroundManager.draw(&window);
        window.display();
    }

    return 0;
}