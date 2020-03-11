#ifndef MAHJONG_BACKGROUNDMANAGER_H
#define MAHJONG_BACKGROUNDMANAGER_H


#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <Enums.h>


//
//
class BackgroundManager final
{
    public:

        BackgroundManager();

        void changeBackground(const Enums::Background::Background LEVEL);

        void draw(sf::RenderWindow& window, const Enums::Stage);

    private:

        void loadTextures();

        constexpr static int PICTURES_LEFT = 4,
                             PICTURES_RIGHT = 4;

        const int BLOCK_SIZE_Y = 270,
                  BLOCK_SIZE_X = 270;

        const std::string PATH_TO_BACKGROUND = "resources/Textures/Backgrounds/";
        const std::string EXTENSION = ".jpg";

        sf::Sprite image;

        std::array<sf::Texture, Enums::Background::BACKGROUND_COUNT>  textures;
};


#endif //MAHJONG_BACKGROUNDMANAGER_H
