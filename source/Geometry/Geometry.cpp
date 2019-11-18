#include "Geometry.h"

#include <fstream>
#include <random>
#include <iostream>

#include "../BackgroundManager/BackgroundManager.h"



Geometry::Geometry():
id(0)
{

}


//
//
void Geometry::draw(sf::RenderWindow& window, const Enums::Stage stage, BackgroundManager& backgroundManager)
{
    for ( auto& rune : runes )
    {
        rune->draw(window);
    }

    return;
}


//
//
void Geometry::deleteRunes(std::shared_ptr<Rune>& first, std::shared_ptr<Rune>& second)
{
    runes.erase(std::remove_if(runes.begin(), runes.end(),
                               [&](std::shared_ptr<Rune>& rune)
                               {
                                   if ( rune->getID() == first->getID() || rune->getID() == second->getID() )
                                   {
                                       sf::Vector3i position = rune->getPosition();
                                       clearCell(position.x, position.y, position.z);
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
bool Geometry::isFree(const int X, const int Y, const int Z)
{
    int x = field[X][Y][Z].x;
    int y = field[X][Y][Z].y;

    for ( int i = Z + 1; i < MAX_DEPTH; ++i )
    {
        for ( int j = 0; j < 2; ++j )
        {
            for ( int k = 0; k < 2; ++k )
            {
                if ( field[x + j][y + k][i].info )
                {
                    return false;
                }
            }
        }
    }

    for ( int i = 0; i <= Z; ++i )
    {
        if( (!field[x - 1][y][i].info && !field[x - 1][y + 1][i].info) ||
            (!field[x + 2][y][i].info && !field[x + 2][y + 1][i].info) )
        {
            return true;
        }
    }

    return false;
}


//
//
[[nodiscard]]
std::shared_ptr<Rune> Geometry::getRune(const int X, const int Y)
{
    int x = Enums::UNDEFINED, y = Enums::UNDEFINED, z = Enums::UNDEFINED;
    std::shared_ptr<Rune> rune = nullptr;
    for ( int height = 0; height < MAX_DEPTH; ++height )
    {
        int x_ = field[((X - (Rune::getOffset().x) * height)/ (Rune::getTextureSize().x / 2) )][((Y + (Rune::getOffset().y) * height) / (Rune::getTextureSize().y / 2))][height].x;
        int y_ = field[((X - (Rune::getOffset().x) * height)/ (Rune::getTextureSize().x / 2)) ][((Y + (Rune::getOffset().y) * height) / (Rune::getTextureSize().y / 2))][height].y;
        if ( x_ == Enums::UNDEFINED || y_ == Enums::UNDEFINED )
        {
            continue;
        }
        if ( x_ > MAX_WIDTH || y_ > MAX_HEIGHT )
        {
            continue;
        }
        if ( field[x_][y_][height].info == true )
        {
            rune = (*std::find_if(runes.begin(), runes.end(),
                    [&](std::shared_ptr<Rune> rune)
                    {
                        if ( field[x_][y_][height].id == rune->getID() )
                        {
                            x = x_;
                            y = y_;
                            z = height;
                            return true;
                        }
                        return false;

                    }));
        }

    }

    if ( x == Enums::UNDEFINED )
    {
        return nullptr;
    }

    if ( isFree( x, y, z ) )
    {
        return rune;
    }
    else
    {
        return nullptr;
    }
}


//
//
void Geometry::loadLevel(const int LEVEL)
{
    clear();

    std::fstream file(PATH_TO_LEVELS + std::to_string(LEVEL) + EXTENSION);
    for ( int y = 0; y < MAX_HEIGHT; ++y )
    {
        for ( int x = 0; x < MAX_WIDTH; ++x )
        {
            char height;
            file >> height;
            for ( int z = 0; z < height - '0'; ++z )
            {
                if ( field[x][y][z].info == false )
                {
                    fillRectangle(x, y, z);
                    ++id;
                }
            }

        }
    }

    runes.resize(id);

    for ( int i = 0; i < id; ++i )
    {
        runes[i] = std::make_shared<Rune>(i);
    }

    generateRunes();

    for ( int i = 0; i < id; ++i )
    {
        runes[i]->setPosition(positions[i].x, positions[i].y, positions[i].z);
    }

    std::sort(runes.begin(), runes.end(),
            [](std::shared_ptr<Rune>& first, std::shared_ptr<Rune>& second)
            {
                return first->getPosition().z < second->getPosition().z;
            }
            );

    return;
}


//
//
void Geometry::clear()
{
    id = 0;
    static Tile tile;

    for ( int x = 0; x < MAX_WIDTH; ++x )
    {
        for ( int y = 0; y < MAX_HEIGHT; ++y )
        {
            for ( int z = 0; z < MAX_DEPTH; ++z )
            {
                field[x][y][z] = tile;
            }
        }
    }

    positions.clear();

    runes.clear();

    return;
}


//
//
void Geometry::clearCell(const int X, const int Y, const int Z)
{
    for ( int i = 0; i < 2; ++i )
    {
        for ( int j = 0; j < 2; ++j )
        {
            field[X + i][Y + j][Z].info = false;
        }
    }

    return;
}


//
//
void Geometry::fillRectangle(const int X, const int Y, const int Z)
{
    for ( int i = 0; i < 2; ++i )
    {
        for ( int j = 0; j < 2; ++j )
        {
            field[X + i][Y + j][Z].id = id;
            field[X + i][Y + j][Z].x = X;
            field[X + i][Y + j][Z].y = Y;
            field[X + i][Y + j][Z].info = true;
        }
    }

    positions.push_back(Position{X, Y, Z});

    return;
}


//  It must be guaranteed that the number of runes is even.
//
void Geometry::generateRunes()
{
    std::vector<int> vec;

    int first, second, temp;
    first = id / RUNES_TYPES_COUNT;
    second = id / RUNES_TYPES_COUNT;
    temp = id - (id / RUNES_TYPES_COUNT) * RUNES_TYPES_COUNT;

    if ( first & 1 )
    {
        --first;
        ++second;
    }

    std::vector<int> runeType;

    for ( int i = 0; i < RUNES_TYPES_COUNT; ++i )
    {
        if ( i & 1 )
        {
            runeType.push_back(first + 2 * (temp ? 1 : 0));
        }
        else
        {
            runeType.push_back(second + 2 * (temp ? 1 : 0));
        }

        if ( temp > 0 )
        {
            temp -= 2;
        }
    }

    for ( int i = 0, j = 0; i < id; ++i )
    {
        if ( runeType[j] != 0 )
        {
            vec.push_back(j);
            --runeType[j];
        }
        else
        {
            ++j;
            --i;
        }
    }

    static std::random_device rd;
    static std::mt19937 g(rd());

    std::shuffle(vec.begin(), vec.end(), g);

    for ( int i = 0; i < id; ++i )
    {
        runes[i]->setRuneType(vec[i]);
    }

    return;
}
