#ifndef MAHJONG_EVENTMANAGER_H
#define MAHJONG_EVENTMANAGER_H


#include "SFML/Window.hpp"

#include "../GameObject/GameObject.h"


//
//
class EventManager final
{
    public :

        void subscribe(GameObject* gameObject);

        void unsubscribe(GameObject* gameObject);

        void pushEvent(sf::Event* event);

    private :
        std::vector<GameObject*> subscribers;
};


#endif //MAHJONG_EVENTMANAGER_H
