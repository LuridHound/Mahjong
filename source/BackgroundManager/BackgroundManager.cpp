#include "BackgroundManager.h"


//
//
BackgroundManager::BackgroundManager()
{
    for ( size_t i = 0; i < BACKGROUND_COUNT; ++i )
    {
        textures[i] = new sf::Texture();

        if ( i == 0 )
        {
            textures[i]->loadFromFile(PATH_TO_BACKGROUND + "Menu" + EXTENSION);
            continue;
        }

        textures[i]->loadFromFile(PATH_TO_BACKGROUND + std::to_string(i) + EXTENSION);
    }
}


//
//
void BackgroundManager::changeBackground(const Enums::Background::Background LEVEL)
{
    image.setTexture(*textures[static_cast<int>(LEVEL)]);

    return;
}


//
//
void BackgroundManager::draw(sf::RenderWindow* window, const Enums::Stage stage)
{
    window->draw(image);

    if ( stage == Enums::Stage::MENU )
    {
        sf::Sprite sprite;
        sprite.setScale(BLOCK_SIZE_X / 1920.0, BLOCK_SIZE_Y / 1080.0);

        for ( int i = 0; i < PICTURES_LEFT; ++i )
        {
            sprite.setTexture(*textures[i + 1]);
            sprite.setPosition(0, BLOCK_SIZE_Y * i);
            window->draw(sprite);
        }

        for ( int i = 0; i < PICTURES_RIGHT; ++i )
        {
            sprite.setTexture(*textures[i + 1 + PICTURES_LEFT]);
            sprite.setPosition(1920 - BLOCK_SIZE_X, BLOCK_SIZE_Y * i);
            window->draw(sprite);
        }
    }

    return;
}