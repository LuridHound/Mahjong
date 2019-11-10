#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "MenuInput.h"
#include "../GameInput/GameInput.h"


//
//
void MenuInput::update(Enums::Stage &stage, User* user, Geometry* geometry)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        user->setLevel(Enums::UserChoice::FIRST);
        stage = Enums::Stage::GAME;
        user->setInput(new GameInput());
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        user->setLevel(Enums::UserChoice::SECOND);
        stage = Enums::Stage::GAME;
        user->setInput(new GameInput());
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    {
        user->setLevel(Enums::UserChoice::THIRD);
        stage = Enums::Stage::GAME;
        user->setInput(new GameInput());
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
    {
        user->setLevel(Enums::UserChoice::FORTH);
        stage = Enums::Stage::GAME;
        user->setInput(new GameInput());
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
    {
        user->setLevel(Enums::UserChoice::FIFTH);
        stage = Enums::Stage::GAME;
        user->setInput(new GameInput());
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
    {
        user->setLevel(Enums::UserChoice::SIXTH);
        stage = Enums::Stage::GAME;
        user->setInput(new GameInput());
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
    {
        user->setLevel(Enums::UserChoice::SEVENTH);
        stage = Enums::Stage::GAME;
        user->setInput(new GameInput());
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
    {
        user->setLevel(Enums::UserChoice::EIGHT);
        stage = Enums::Stage::GAME;
        user->setInput(new GameInput());
        return;
    }
/*
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
    {
        user->setLevel(Enums::Level::FIRST);
        stage = Enums::Stage::GAME;
        user->setInput(new GameInput());
    }
*/
    return;
}