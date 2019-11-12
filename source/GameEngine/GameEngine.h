#ifndef MAHJONG_GAMEENGINE_H
#define MAHJONG_GAMEENGINE_H


#include "../Enums.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "../BackgroundManager/BackgroundManager.h"
#include "../Geometry/Geometry.h"
#include "../User/User.h"
#include "../EventManager/EventManager.h"


//
//
class GameEngine final
{
    public :

        GameEngine();

        void run();

    private :

        void initializeWindow();

        const char* title = "Mahjong";

        Enums::Stage stage;

        Enums::UserChoice tempLevel;

        sf::RenderWindow* window;

        EventManager* eventManager;

        BackgroundManager* backgroundManager;
        Geometry geometry;
        User* user;
};


#endif //MAHJONG_GAMEENGINE_H
