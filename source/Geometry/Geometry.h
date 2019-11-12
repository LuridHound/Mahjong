#ifndef MAHJONG_GEMOMETRY_H
#define MAHJONG_GEMOMETRY_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../Rune/Rune.h"
#include "../Enums.h"
#include "../BackgroundManager/BackgroundManager.h"


//
//
class Geometry final
{
    public :

        void draw(sf::RenderWindow* window, const Enums::Stage stage, BackgroundManager* backgroundManager);

        void deleteRunes(Rune* first, Rune* second);

        [[nodiscard]]
        bool isFree(int x, int y, int z);

        [[nodiscard]]
        bool isFree(Rune* rune);

        [[nodiscard]]
        Rune* getRune(int x, int y);

        void loadLevel(const int LEVEL);

        [[nodiscard]]
        bool isEmpty() const;

        void clear();

    private :

        void clearCell(int x, int y, int z);

        void fillRectangle(const int X, const int Y, const int Z);
        void generateRunes();

    struct Position
                {
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

        constexpr static int RUNES_TYPES_COUNT = 36;

        Tile field[MAX_WIDTH][MAX_HEIGHT][MAX_DEPTH]={};
        std::vector<Rune*> runes;
};


#endif //MAHJONG_GEMOMETRY_H
