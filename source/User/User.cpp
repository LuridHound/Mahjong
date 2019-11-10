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
    input->update(stage, this, geometry);

    return;
}


//
//
void User::setRune(Rune *rune)
{
    if ( first == nullptr )
    {
        first = rune;
    }

    if ( second == nullptr )
    {
        second = rune;
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