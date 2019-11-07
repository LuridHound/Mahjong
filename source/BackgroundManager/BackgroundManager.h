#ifndef MAHJONG_BACKGROUNDMANAGER_H
#define MAHJONG_BACKGROUNDMANAGER_H


#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


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

        void changeBackground();

        void draw(sf::RenderWindow* window);

    private:

        constexpr static size_t BACKGROUND_COUNT = 8u;

        const std::string PATH_TO_BACKGROUND = "resources/Backgrounds/";
        const std::string EXTENSION = ".jpg";

        sf::Sprite image;

        std::array<sf::Texture*, BACKGROUND_COUNT>  textures;
};



#endif //MAHJONG_BACKGROUNDMANAGER_H
