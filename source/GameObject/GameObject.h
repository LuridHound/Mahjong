#ifndef MAHJONG_GAMEOBJECT_H
#define MAHJONG_GAMEOBJECT_H


#include <vector>

#include <SFML/Window/Event.hpp>


//
//
class GameObject
{
    public :

        virtual void respondEvent() = 0;

        void getEvent(sf::Event* event);

    protected :

        std::vector<sf::Event*> events;
};


#endif //MAHJONG_GAMEOBJECT_H
