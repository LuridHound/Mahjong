#ifndef MAHJONG_RUNE_H
#define MAHJONG_RUNE_H


#include <cstddef>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>


//
//
class Rune final
{
    public :

        explicit Rune(const int ID);

        void setPosition(const int x, const int y, const int z);

        [[nodiscard]]
        size_t getType() const;

        [[nodiscard]]
        int getID() const;

        void setRuneType(const int TYPE);
        void draw(sf::RenderWindow* window);

        [[nodiscard]]
        sf::Vector3i getPosition();

        void highlight();
        void unhighlight();


        [[nodiscard]]
        static sf::Vector2i getOffset();
        [[nodiscard]]
        static sf::Vector2i getTextureSize();

    private :

        static int offsetX, offsetY;
        static int textureSizeX, textureSizeY;

        constexpr static int FACTOR = 7;

        bool ishHighlighted;

        int x, y, z;

        const int ID;

        size_t type;

        sf::Texture texture;
        sf::Sprite sprite;
};


#endif //MAHJONG_RUNE_H