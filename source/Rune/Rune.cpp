#include "Rune.h"


int Rune::offsetX, Rune::offsetY;
int Rune::textureSizeX, Rune::textureSizeY;

//
//
Rune::Rune(const int ID):
ishHighlighted(false),
ID(ID)
{
    texture.loadFromFile("resources/Textures/Runes/0.png");
    sprite.setTexture(texture);

    textureSizeX = texture.getSize().x;
    textureSizeY = texture.getSize().y;
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
void Rune::setPosition(const int X, const int Y, const int Z)
{
    sprite.setPosition(textureSizeX * (X / 2) + (textureSizeX / 2) * (X % 2) + Z * offsetX,
                       textureSizeY * (Y / 2) + (textureSizeY / 2) * (Y % 2) - Z * offsetY);

    return;
}


//  Return the ID of the rune.
//  Each rune must have unique ID.
[[nodiscard]]
int Rune::getID() const
{
    return ID;
}


//
//
void Rune::highlight()
{
    if ( !ishHighlighted )
    {
        sprite.setColor(sf::Color(255, 255, 255, 215));
        ishHighlighted = true;
    }

    return;
}


//
//
void Rune::unhighlight()
{
    if ( ishHighlighted )
    {
        sprite.setColor(sf::Color(255, 255, 255, 255));
        ishHighlighted = false;
    }

    return;
}