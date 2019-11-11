#include "User.h"
#include "../Input/MenuInput/MenuInput.h"


//
//
User::User():
choice{Enums::UserChoice::MENU},
input(new MenuInput())
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
void User::setInput(Input* input_)
{
    delete input;
    input = input_;

    return;
}


//
//
void User::update(Enums::Stage& stage, Geometry* geometry)
{
    respondEvent();

    for(auto event : events)
    {
        input->update(stage, this, geometry, event);
    }

    if(first != nullptr)
    {
        first->highlight();
    }

    if ( first == second && first != nullptr )
    {
        first->unhighlight();
        first = second = nullptr;
    }

    if ( first != nullptr && second != nullptr )
    {
        first->unhighlight();
        second->unhighlight();
        if ( first->getType() == second->getType() )
        {
            geometry->deleteRunes(first, second);
        }
        first = second = nullptr;
    }

    events.clear();

    return;
}


//
//
void User::setRune(Rune *rune)
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
Enums::UserChoice User::levelChoice()
{
    return choice;
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
void User::clear()
{
    first = second = nullptr;

    return;
}