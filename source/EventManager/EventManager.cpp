#include "EventManager.h"


//
//
void EventManager::subscribe(GameObject* gameObject)
{
    std::vector<GameObject*>::iterator it = std::find(subscribers.begin(), subscribers.end(), gameObject);
    if ( it == subscribers.end() )
    {
        subscribers.push_back(gameObject);
    }

    return;
}


//
//
void EventManager::unsubscribe(GameObject* gameObject)
{
    std::vector<GameObject*>::iterator it = std::find(subscribers.begin(), subscribers.end(), gameObject);
    if ( it != subscribers.end() )
    {
        subscribers.erase(it);
    }

    return;
}


//
//
void EventManager::pushEvent(sf::Event* event)
{
    for ( auto& subscriber : subscribers )
    {
        subscriber->getEvent(event);
    }

    return;
}