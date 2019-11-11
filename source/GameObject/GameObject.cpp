#include "GameObject.h"


//
//
void GameObject::getEvent(sf::Event* event)
{
    events.push_back(event);

    return;
}