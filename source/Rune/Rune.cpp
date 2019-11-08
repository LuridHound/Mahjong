#include "Rune.h"


//
//
Rune::Rune(int id):
id(id)
{
    type = rand() % 33;
    texture.loadFromFile("resources/Textures/Runes/" + std::to_string(type) + ".png");
    sprite.setTexture(texture);
    offset_x = texture.getSize().x / 12;
    offset_y = texture.getSize().y / 12;
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


//
//
void Rune::setPosition(int x, int y, int z)
{
    sprite.setPosition(texture.getSize().x * (x / 2) + (texture.getSize().x / 2) * (x % 2) + z * offset_x,
                       texture.getSize().y * (y / 2) + (texture.getSize().y / 2) * (y % 2) - z * offset_y);

    return;
}


//
//
[[nodiscard]]
int Rune::getID() const
{
    return id;
}