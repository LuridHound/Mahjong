#include "Geometry.h"

#include <fstream>
#include <iostream>


//
//
void Geometry::draw(sf::RenderWindow *window)
{
    for ( auto& rune : runes )
    {
        if(rune != nullptr)
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

    positions.push_back(Position{x, y, z});

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
Rune* Geometry::getRune(int x, int y)
{
    Rune* rune = nullptr;
    for ( int z = 0; z < MAX_DEPTH; ++z )
    {
        int x_ = field[(x / 27)][(y / 45)][z].x;
        int y_ = field[(x / 27)][(y / 45)][z].y;
        if ( x_ == -1 || y_ == -1 )
            continue;
        if ( field[x_][y_][z].info == true )

        rune = (*std::find_if(runes.begin(), runes.end(), [&](Rune* rune){
            if ( field[x_][y_][z].id == rune->getID() )
            {
                return true;
            }
            return false;

        }));
    }

    return rune;
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

    for ( auto& rune : runes )
    {
        rune->setRuneType(2);
    }

    runes.reserve(id);

    for ( int i = 0; i < id; ++i )
    {
        runes.push_back(new Rune(i));
        runes[i]->setRuneType(rand() % 30);
        runes[i]->setPosition(positions[i].x, positions[i].y, positions[i].z);
        runes[i]->x = positions[i].x;
        runes[i]->y = positions[i].y;
        runes[i]->z = positions[i].z;

    }

    std::sort(runes.begin(), runes.end(),
            [](Rune* first, Rune* second)
            {
                if(first->z < second->z)
                    return true;
                return false;
            }
            );

    return;
}


//
//
void Geometry::clearCell(const int X, const int Y, const int Z)
{
    for ( int i = 0; i < 2; ++i )
    {
        for(int j = 0; j < 2; ++j)
        {
            field[X + i][Y + j][Z].info = false;
        }
    }

    return;
}


//
//
void Geometry::deleteRunes(Rune* first, Rune* second)
{
    runes.erase(std::remove_if(runes.begin(), runes.end(),
            [&](Rune* rune)
            {
                if ( rune->getID() == first->getID() || rune->getID() == second->getID() )
                {
                    clearCell(rune->x, rune->y, rune->z);
                    return true;
                }
                return false;
            }
    ), runes.end());

    return;
}


//
//
[[nodiscard]]
bool Geometry::isEmpty() const
{
    return runes.empty();
}