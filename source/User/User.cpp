#include "User.h"
#include "../Input/MenuInput/MenuInput.h"


//
//
User::User():
input(new MenuInput())
{

}


//
//
void User::setInput(Input* input_)
{
    delete input;
    input = input_;
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
Enums::Level User::levelChoice()
{
    return choice;
}


//
//
void User::setLevel(const Enums::Level level)
{
    choice = level;

    return;
}