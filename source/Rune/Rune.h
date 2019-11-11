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

        Rune(const int ID);

        void setPosition(const int x, const int y, const int z);

        [[nodiscard]]
        size_t getType() const;

        [[nodiscard]]
        int getID() const;

        void setRuneType(const int TYPE);
        void draw(sf::RenderWindow* window);
        int x, y, z;    // get rid

        void highlight();
        void unhighlight();

    private :

        static int offsetX, offsetY;
        static int textureSizeX, textureSizeY;

        constexpr static int FACTOR = 7;

        bool ishHighlighted;

        const int ID;

        size_t type;

        sf::Texture texture;
        sf::Sprite sprite;
};


#endif //MAHJONG_RUNE_H