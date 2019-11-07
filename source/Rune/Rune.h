#ifndef MAHJONG_RUNE_H
#define MAHJONG_RUNE_H


#include <cstddef>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


//
//
class Rune final
{
    public :
        Rune();

        [[nodiscard]]
        size_t getType() const;

        void draw(sf::RenderWindow* window);

    private :
        size_t type;
        sf::Texture texture;
        sf::Sprite sprite;
};


#endif //MAHJONG_RUNE_H
