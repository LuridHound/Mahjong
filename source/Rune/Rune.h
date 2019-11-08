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

        void setPosition(int x, int y, int z);

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
        constexpr static int FACTOR = 12;
        const int ID;
        int offsetX, offsetY;
        size_t type;
        sf::Texture texture;
        sf::Sprite sprite;
};


#endif //MAHJONG_RUNE_H