#include "Rune.h"


int Rune::offsetX, Rune::offsetY;


//
//
Rune::Rune(const int ID):
ID(ID)
{
    texture.loadFromFile("resources/Textures/Runes/0.png");
    sprite.setTexture(texture);
}


//
//
void Rune::highlight()
{
    sprite.setColor(sf::Color(255, 255, 255, 215));

    return;
}


//
//
void Rune::unhighlight()
{
    sprite.setColor(sf::Color(255, 255, 255, 255));

    return;
}


//
//
void Rune::setRuneType(const int TYPE)
{
    type = TYPE;
    texture.loadFromFile("resources/Textures/Runes/" + std::to_string(TYPE) + ".png");

    offsetX = texture.getSize().x / FACTOR;
    offsetY = texture.getSize().y / FACTOR;

    return;
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
    sprite.setPosition(texture.getSize().x * (x / 2) + (texture.getSize().x / 2) * (x % 2) + z * offsetX,
                       texture.getSize().y * (y / 2) + (texture.getSize().y / 2) * (y % 2) - z * offsetY);

    return;
}


//
//
[[nodiscard]]
int Rune::getID() const
{
    return ID;
}