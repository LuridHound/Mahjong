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
void BackgroundManager::draw(sf::RenderWindow* window)
{
    window->draw(image);

    return;
}