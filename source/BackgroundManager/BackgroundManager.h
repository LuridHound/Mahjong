#ifndef MAHJONG_BACKGROUNDMANAGER_H
#define MAHJONG_BACKGROUNDMANAGER_H


#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Enums.h"


//  TODO
//  make normal generator
template <class T>
T generateRandomNumber(T minimum = 0, T maximum = 2)
{
    return 0;
}


//
//
class BackgroundManager final
{
    public:

        BackgroundManager();

        void changeBackground(const Enums::Background::Background LEVEL);

        void draw(sf::RenderWindow* window);

    private:

        constexpr static size_t BACKGROUND_COUNT = 9u;

        const std::string PATH_TO_BACKGROUND = "resources/Textures/Backgrounds/";
        const std::string EXTENSION = ".jpg";

        sf::Sprite image;

        std::array<sf::Texture*, Enums::Background::BACKGROUND_COUNT>  textures;
};



#endif //MAHJONG_BACKGROUNDMANAGER_H
