#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "source/BackgroundManager/BackgroundManager.h"

constexpr size_t MAX_WIDTH = 40u,
                MAX_HEIGHT = 20u,
                MAX_DEPTH = 7u;


int ar[MAX_WIDTH][MAX_HEIGHT][MAX_DEPTH]={};


int main()
{

    const char* title = "Mahjong";
    sf::RenderWindow window(sf::VideoMode(1920, 1080), title);

    sf::Texture text;
    sf::Sprite sprite;
    text.loadFromFile("resources/Textures/Runes/1.png");
    sprite.setTexture(text);

    std::fstream file("resources/Levels/Level.txt");
    for(int y = 0; y < 20 - 1; ++y)
    for(int x = 0; x < 40 - 1; ++x)
    {
        char a;
        file >> a;
        for(int i = 0; i < a - '0'; ++i)
        {
            if(!ar[x][y][i])
            {
                ar[x][y][i] = 1;
                ar[x + 1][y][i] = 1;
                ar[x][y + 1][i] = 1;
                ar[x + 1][y + 1][i] = 1;

            }
        }

    }


    BackgroundManager backgroundManager;
    backgroundManager.changeBackground();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << sf::Mouse::getPosition().x << ' ' << sf::Mouse::getPosition().y << '\n';
            }

        }

        window.clear();

        backgroundManager.draw(&window);

        int buffer[40][20][7]={0};

        for(int i = 0; i < 7; ++i) {

            for (int y = 0; y < 20 - 1; ++y)
                for (int x = 0; x < 40 - 1; ++x) {
                    {
                        if (buffer[x][y][i] != ar[x][y][i]) {
                            buffer[x][y][i] = 1;
                            buffer[x + 1][y][i] = 1;
                            buffer[x][y + 1][i] = 1;
                            buffer[x + 1][y + 1][i] = 1;
                            sprite.setPosition(text.getSize().x * (x / 2) + text.getSize().x / 2 * (x % 2) +
                                               text.getSize().x / 12 * i,
                                               text.getSize().y * (y / 2) + text.getSize().y / 2 * (y % 2) -
                                               text.getSize().y / 12 * i);
                            window.draw(sprite);
                        }
                    }

                }
        }
        window.draw(sprite);
        window.display();
    }

    return 0;
}