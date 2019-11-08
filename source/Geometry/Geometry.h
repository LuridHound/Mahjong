#ifndef MAHJONG_GEMOMETRY_H
#define MAHJONG_GEMOMETRY_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../Rune/Rune.h"


//
//
class Geometry final
{
public :
    void draw(sf::RenderWindow* window);

    void deleteRunes(Rune* first, Rune* second);

    [[nodiscard]]
    bool isFree(int x, int y, int z);

    [[nodiscard]]
    bool isFree(const int id_first, const int id_second);

    void fillRectangle(int x, int y, int z);

    [[nodiscard]]
    bool isFree(Rune* rune);

    [[nodiscard]]
    Rune* getRune(int x, int y);

    void loadLevel();

    void clearCell(int x, int y, int z);

    [[nodiscard]]
    bool isEmpty() const;

    void generateRunes();
private :
    struct Position
            {
            public :
                int x, y, z;
            };
    std::vector<Position> positions;
    int id = 0;
    //beware
    struct Tile
            {
                int x = - 1, y = -1;
                bool info = false;
                int id = -1;
            };
    constexpr static size_t MAX_WIDTH = 70u,
            MAX_HEIGHT = 24u,
            MAX_DEPTH = 7u;
    constexpr static int RUNES_COUNT = 36;
    Tile field[MAX_WIDTH][MAX_HEIGHT][MAX_DEPTH]={};
    std::vector<Rune*> runes;
};


#endif //MAHJONG_GEMOMETRY_H
