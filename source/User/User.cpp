#include <memory>
#include <iostream>
#include "User.h"
#include "../Input/MenuInput/MenuInput.h"


//
//
User::User():
choice{Enums::UserChoice::MENU},
input( std::make_unique<MenuInput>( MenuInput()) )
{

}


//
//
void User::respondEvent()
{
    return;
}


//
//
void User::update(Enums::Stage& stage, Geometry& geometry)
{
    respondEvent();

    for ( auto event : events )
    {
        input->update(stage, *this, geometry, event);
    }

    if ( first != nullptr )
    {
        first->highlight();
    }

    if ( first == second && first != nullptr )
    {
        first->unhighlight();
        clear();
    }

    if ( first != nullptr && second != nullptr )
    {
        first->unhighlight();
        second->unhighlight();
        if ( first->getType() == second->getType() )
        {
            geometry.deleteRunes(first, second);
        }
        clear();
    }

    events.clear();

    return;
}


//
//
void User::setInput(std::unique_ptr<Input> input_)
{
    input = std::move(input_);

    return;
}


//
//
void User::setRune(std::shared_ptr<Rune>& rune)
{
    if ( first == nullptr )
    {
        first = rune;
        return;
    }

    if ( second == nullptr )
    {
        second = rune;
        return;
    }

    return;
}


//
//
void User::setLevel(const Enums::UserChoice level)
{
    choice = level;

    return;
}


//
//
[[nodiscard]]
Enums::UserChoice User::levelChoice()
{
    return choice;
}


//
//
void User::clear()
{
    first.reset();
    second.reset();

    return;
}