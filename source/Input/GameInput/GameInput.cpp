#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "GameInput.h"
#include "../MenuInput/MenuInput.h"

//
//
void GameInput::update(Enums::Stage& stage, User* user, Geometry* geometry)
{
    /*
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::))
*/
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        stage = Enums::Stage::MENU;
        user->setInput(new MenuInput());
    }
    int x = sf::Mouse::getPosition().x;
    int y = sf::Mouse::getPosition().y;
/*
    user->setRune(geometry->getRune(x, y));

    auto rune = geometry->getRune(x, y);

    if ( rune == nullptr )
    {
        if ( first != nullptr )
        {
            first->highlight();
        }
    }
    else
    {
        second = geometry.getRune(x, y);
        if ( second == nullptr )
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

        if ( first->getType() == second->getType() )
            geometry.deleteRunes(first, second);
        first = nullptr;
        second = nullptr;
    }

*/
    return;
}