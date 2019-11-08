#ifndef MAHJONG_GAMEENGINE_H
#define MAHJONG_GAMEENGINE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../BackgroundManager/BackgroundManager.h"

#include "../Geometry/Geometry.h"


//
//
class GameEngine final
{
    public :
        GameEngine();
        void run();

    private :

        const char* title = "Mahjong";

        BackgroundManager backgroundManager;
        Geometry geometry;

        sf::RenderWindow* window;
};


#endif //MAHJONG_GAMEENGINE_H
