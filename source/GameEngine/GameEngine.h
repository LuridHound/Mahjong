#ifndef MAHJONG_GAMEENGINE_H
#define MAHJONG_GAMEENGINE_H


#include "../Enums.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "../BackgroundManager/BackgroundManager.h"
#include "../Geometry/Geometry.h"
#include "../User/User.h"


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

        BackgroundManager* backgroundManager;
        Geometry geometry;
        User* user;

        Enums::UserChoice tempLevel;

        sf::RenderWindow* window;
};


#endif //MAHJONG_GAMEENGINE_H
