#include "Rune.h"


//
//
Rune::Rune()
{
    texture.loadFromFile("resources/Textures/Runes/0.png");
    sprite.setTexture(texture);
}


//
//
[[nodiscard]]
size_t Rune::getType() const
{
    return type;
}


//
//
void Rune::draw(sf::RenderWindow* window)
{
    window->draw(sprite);

    return;
}
