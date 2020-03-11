#ifndef MAHJONG_GEMOMETRY_H
#define MAHJONG_GEMOMETRY_H


#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include <Rune/Rune.h>
#include <Enums.h>
#include <BackgroundManager/BackgroundManager.h>


//
//
class Geometry final
{
    public :

        Geometry();

        void draw(sf::RenderWindow& window, const Enums::Stage stage, BackgroundManager& backgroundManager);

        void deleteRunes(std::shared_ptr<Rune>& first, std::shared_ptr<Rune>& second);

        [[nodiscard]]
        bool isFree(const int X, const int Y, const int Z);

        [[nodiscard]]
        std::shared_ptr<Rune> getRune(const int X, const int Y);

        void loadLevel(const int LEVEL);

    private :

        void clear();

        void clearCell(int x, int y, int z);

        void fillRectangle(const int X, const int Y, const int Z);
        void generateRunes();

        struct Position
        {
            int x;
            int y;
            int z;
        };

        struct Tile
         {
            int x = Enums::UNDEFINED, y = Enums::UNDEFINED;
            bool info = false;
            int id = Enums::UNDEFINED;
         };

        int id;

        constexpr static size_t MAX_WIDTH = 70u,
                                MAX_HEIGHT = 24u,
                                MAX_DEPTH = 7u;

        constexpr static int RUNES_TYPES_COUNT = 36;

        const std::string PATH_TO_LEVELS = "resources/Levels/";
        const std::string EXTENSION = ".txt";

        Tile field[MAX_WIDTH][MAX_HEIGHT][MAX_DEPTH] = {};

        std::vector<Position> positions;

        std::vector<std::shared_ptr<Rune>> runes;
};


#endif //MAHJONG_GEMOMETRY_H
