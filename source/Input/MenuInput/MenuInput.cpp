#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "MenuInput.h"
#include "../GameInput/GameInput.h"


//
//
void MenuInput::update(Enums::Stage &stage, User& user, Geometry& geometry, sf::Event* event)
{
    if ( event->type == sf::Event::KeyPressed )
    {

        if ( event->key.code >= sf::Keyboard::Num1 && event->key.code <= sf::Keyboard::Num8 )
        {
            user.setLevel(static_cast<Enums::UserChoice>(event->key.code - sf::Keyboard::Num0));
            stage = Enums::Stage::GAME;
            user.setInput(std::make_unique<GameInput>());
        }

    }

    return;

}