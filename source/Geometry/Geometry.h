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

    void deleteById(const int first_id, const int second_id);

    void deleteRunes(Rune* first, Rune* second);

    [[nodiscard]]
    bool isFree(int x, int y, int z);

    [[nodiscard]]
    bool isFree(const int id_first, const int id_second);

    void fillRectangle(int x, int y, int z);

    [[nodiscard]]
    int getRuneID(int x, int y);

    void loadLevel();

    void clearCell(int x, int y, int z);

    [[nodiscard]]
    bool isEmpty() const;
public :

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

    Tile field[MAX_WIDTH][MAX_HEIGHT][MAX_DEPTH]={};
    std::vector<Rune*> runes;
};


#endif //MAHJONG_GEMOMETRY_H
