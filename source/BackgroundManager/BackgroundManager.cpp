#include "BackgroundManager.h"


//
//
BackgroundManager::BackgroundManager()
{
    loadTextures();
}


//
//
void BackgroundManager::changeBackground(const Enums::Background::Background LEVEL)
{
    image.setTexture(textures[static_cast<int>(LEVEL)]);

    return;
}


//
//
void BackgroundManager::draw(sf::RenderWindow& window, const Enums::Stage stage)
{
    window.draw(image);

    if ( stage == Enums::Stage::MENU )
    {
        sf::Sprite sprite;
        sprite.setScale(BLOCK_SIZE_X / 1920.0, BLOCK_SIZE_Y / 1080.0);

        for ( int i = 0; i < PICTURES_LEFT; ++i )
        {
            sprite.setTexture(textures[i + 1]);
            sprite.setPosition(0, static_cast<float>(BLOCK_SIZE_Y * i));
            window.draw(sprite);
        }

        for ( int i = 0; i < PICTURES_RIGHT; ++i )
        {
            sprite.setTexture(textures[i + 1 + PICTURES_LEFT]);
            sprite.setPosition(1920.0f - static_cast<float>(BLOCK_SIZE_X), static_cast<float>(BLOCK_SIZE_Y * i));
            window.draw(sprite);
        }
    }

    return;
}


//
//
void BackgroundManager::loadTextures()
{
    for ( int i = 0; i < textures.size(); ++i )
    {
        if ( i == 0 )
        {
            textures[i].loadFromFile(PATH_TO_BACKGROUND + "Menu" + EXTENSION);
        }
        else
        {
            textures[i].loadFromFile(PATH_TO_BACKGROUND + std::to_string(i) + EXTENSION);
        }
    }

    return;
}