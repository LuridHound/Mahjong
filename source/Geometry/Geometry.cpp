#include "Geometry.h"
#include "../BackgroundManager/BackgroundManager.h"

#include <fstream>
#include <iostream>
#include <random>


//
//
void Geometry::draw( sf::RenderWindow *window, const Enums::Stage stage, BackgroundManager* backgroundManager )
{
    switch ( stage )
    {
        case Enums::Stage::MENU :
        {
            backgroundManager->changeBackground(Enums::Background::Background::MENU);
            break;
        }

        case Enums::Stage::GAME :
        {
            backgroundManager->changeBackground(Enums::Background::Background::FIRST_LEVEL);

            for ( auto& rune : runes )
            {
                if(rune != nullptr)
                    rune->draw(window);
            }
            break;
        }

        default :
            {
                std::terminate();
            }
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

    for(int i = z + 1; i < MAX_DEPTH; ++i)
    {
        for ( int j = 0; j < 2; ++j )
            for ( int k = 0; k < 2; ++k )
        if ( field[x + j][y + k][i].info )
        {
            return false;
        }
    }

    for ( int i = 0; i <= z; ++i )
    {
        if( (!field[x - 1][y][i].info && !field[x - 1][y + 1][i].info) || (!field[x + 2][y][i].info && !field[x + 2][y + 1][i].info) )
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
bool isFree(Rune* rune)
{

}


//
//
[[nodiscard]]
Rune* Geometry::getRune(int x, int y)
{
    int x_1 = -1, y_1 = -1, z_1 = -1;
    Rune* rune = nullptr;
    for ( int z = 0; z < MAX_DEPTH; ++z )
    {
        int x_ = field[((x - (54 / 12) * z)/ 27)][((y + (90 / 12) * z) / 45)][z].x;
        int y_ = field[((x - (54 / 12) * z)/ 27)][((y + (90 / 12) * z) / 45)][z].y;
        if ( x_ == -1 || y_ == -1 )
            continue;
        if(x_ > MAX_WIDTH || y_ > MAX_HEIGHT)
            continue;
        if ( field[x_][y_][z].info == true )

        rune = (*std::find_if(runes.begin(), runes.end(), [&](Rune* rune){
            if ( field[x_][y_][z].id == rune->getID() )
            {
                x_1 = x_;
                y_1 = y_;
                z_1 = z;
                return true;
            }
            return false;

        }));
    }

    if(x_1 == -1)
    {
        return nullptr;
    }

    if ( isFree( x_1, y_1, z_1 ) )
        return rune;
    else
        return nullptr;
}


//
//  It must be guaranteed that the number of runes is even.
void Geometry::generateRunes()
{
    std::vector<int> vec;

    int first, second, temp;
    first = id / RUNES_COUNT;
    second = id / RUNES_COUNT;
    temp = id - id / RUNES_COUNT * RUNES_COUNT;

    if ( first & 1 )
    {
        --first;
        ++second;
    }

    std::vector<int> runeType;

    for ( int i = 0; i < RUNES_COUNT; ++i )
    {

        if ( i & 1 )
        {
            runeType.push_back(first + 2 * (temp ? 1 : 0));
        }
        else
        {
            runeType.push_back(second + 2 * (temp ? 1 : 0));
        }
        if(temp > 0)
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

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
    std::shuffle(vec.begin(), vec.end(), g);
    std::shuffle(vec.begin(), vec.end(), g);
    std::shuffle(vec.begin(), vec.end(), g);

    for ( int i = 0; i < id; ++i )
    {
        runes[i]->setRuneType(vec[i]);
    }

    return;
}


//
//
void Geometry::loadLevel(const int LEVEL)
{
    std::fstream file("resources/Levels/" + std::to_string(3) + ".txt");
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
    generateRunes();

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