#include "BackgroundManager.h"


//
//
BackgroundManager::BackgroundManager()
{
    for ( size_t i = 0; i < BACKGROUND_COUNT; ++i )
    {
        textures[i] = new sf::Texture();
        textures[i]->loadFromFile(PATH_TO_BACKGROUND + std::to_string(i + 1) + EXTENSION);
    }
}


//
//
void BackgroundManager::changeBackground()
{
    image.setTexture(*textures[generateRandomNumber<int>()]);

    return;
}


//
//
void BackgroundManager::draw(sf::RenderWindow* window)
{
    window->draw(image);

    return;
}