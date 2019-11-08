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
        Rune(int id);

        void setPosition(int x, int y, int z);

        [[nodiscard]]
        size_t getType() const;

        [[nodiscard]]
        int getID() const;

        void draw(sf::RenderWindow* window);
        int x, y, z;    // get rid
    private :
        int id;
        int offset_x, offset_y;
        size_t type;
        sf::Texture texture;
        sf::Sprite sprite;
};


#endif //MAHJONG_RUNE_H