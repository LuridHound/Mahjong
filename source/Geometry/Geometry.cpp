#include "Geometry.h"

#include <fstream>
#include <iostream>


//
//
void Geometry::draw(sf::RenderWindow *window)
{
    for ( auto& rune : runes )
    {
        rune->draw(window);
    }


    return;
}


//
//
[[nodiscard]]
bool Geometry::isFree(int x_, int y_, int z)
{
    int x = field[x_][y_][z].x;
    int y = field[x_][y_][z].y;

    for ( int i = z; i < MAX_DEPTH; ++i )
    {
        if ( !(field[x - 2][y][i].info || field[x + 2][y][i].info) )
        {
            return true;
        }
    }

    return false;
}


//
//
void Geometry::fillRectangle(int x, int y, int z)
{
    for ( int i = 0; i < 2; ++i )
    {
        for ( int j = 0; j < 2; ++j )
        {
            field[x + i][y + j][z].id = id;
            field[x + i][y + j][z].x = x;
            field[x + i][y + j][z].y = y;
            field[x + i][y + j][z].info = true;
        }
    }

    runes.push_back(new Rune(id));
    runes[runes.size() - 1]->setPosition(x, y, z);
    runes[runes.size() - 1]->x = x;
    runes[runes.size() - 1]->y = y;
    runes[runes.size() - 1]->z = z;

    return;
}


//
//
[[nodiscard]]
bool Geometry::isFree(const int id_first, const int id_second)
{
    (*std::find_if(runes.begin(), runes.end(), [&](Rune* rune){ if(rune->getID() == id_first) return true;}))->x;
    return true;
}



//
//
[[nodiscard]]
int Geometry::getRuneID(int x, int y)
{
    int id = -1;
    for(int z = 0; z < MAX_DEPTH; ++z)
    {
        std :: cout << "X" << (x ) / 27 ;
        std::cout << "Y" << (y) / 45 << '\n';
        int x_ = field[(x / 27/*  - (27 / 12) * 3 * z) / 27 */)][(y / 45/* + (45 / 12) * 3 * z) / 45*/)][z].x;
        int y_ = field[(x / 27/* - (27 / 12) * 3 * z) / 27  */)][(y / 45/*+ (45 / 12) * 3 * z) / 45 */)][z].y;
        if(x_ == -1 || y_ == -1)
            continue;
                if(field[x_][y_][z].info == true)
                    id = field[x_][y_][z].id;
    }

    return id;
}


//
//
void Geometry::loadLevel()
{
    std::fstream file("resources/Levels/Level.txt");
    for ( int y = 0; y < MAX_HEIGHT; ++y )
        for ( int x = 0; x < MAX_WIDTH; ++x )
        {
            char a;
            file >> a;
            for ( int z = 0; z < a - '0'; ++z )
            {
                if ( field[x][y][z].info == false )
                {
                    fillRectangle(x, y, z);
                    ++id;
                    std::cout << id << '\n';
                }
            }

        }

    std::cout << id;

        std::sort(runes.begin(), runes.end(), [](Rune* first, Rune* second){if(first->z < second->z) return true;
        return false;});

    return;
}


//
//
void Geometry::clearCell(int x, int y, int z)
{
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            field[x + i][y + j][z].info = false;
        }
    }
}


//
//
void Geometry::deleteById(const int first_id, const int second_id)
{
    runes.erase(std::remove_if(runes.begin(), runes.end(), [&](Rune* rune){if(rune->getID() == first_id || rune->getID() == second_id){
        clearCell(rune->x, rune->y, rune->z);
        return true;}
    return false;}
    ), runes.end());
}



//
//
[[nodiscard]]
bool Geometry::isEmpty() const
{
    return runes.empty();
}