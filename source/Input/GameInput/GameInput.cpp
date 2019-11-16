#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "GameInput.h"
#include "../MenuInput/MenuInput.h"

//
//
void GameInput::update(Enums::Stage& stage, User* user, Geometry* geometry, sf::Event* event)
{
    if ( event->type == sf::Event::KeyPressed )
    {
        if ( event->key.code == sf::Keyboard::Escape )
        {
            user->setLevel(Enums::UserChoice::MENU);
            stage = Enums::Stage::MENU;
            user->setInput(new MenuInput());
        }
    }

    if ( event->type == sf::Event::MouseButtonPressed )
    {
        int x = sf::Mouse::getPosition().x;
        int y = sf::Mouse::getPosition().y;

        auto rune = geometry->getRune(x, y);

        user->setRune(rune);
    }

#ifdef __linux__
    if ( event->type == sf::Event::KeyPressed )
    {
        if ( event->key.code == sf::Keyboard::S )
        {
            system("gnome-screenshot");
        }
    }
#endif

    return;
}