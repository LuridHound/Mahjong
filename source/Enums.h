#ifndef MAHJONG_ENUMS_H
#define MAHJONG_ENUMS_H

#include <cstddef>


//
//
namespace Enums
{
    enum class Stage : int
    {
        MENU = 0,
        GAME = 1
    };

    const int UNDEFINED = -1;

    //
    //
    namespace Background
    {
        enum class Background : int
        {
            MENU = 0,
            FIRST_LEVEL = 1,
            SECOND_LEVEL = 2,
            THIRD_LEVEL = 3,
            FOURTH_LEVEL = 4,
            FIFTH_LEVEL = 5,
            SIXTH_LEVEL = 6,
            SEVENTH_LEVEL = 7,
            EIGHTH_LEVEL = 8
        };
        constexpr static size_t BACKGROUND_COUNT = 9u;
    }


    enum class UserChoice : int
    {
        MENU = 0,
        FIRST = 1,
        SECOND = 2,
        THIRD = 3,
        FOURTH = 4,
        FIFTH = 5,
        SIXTH = 6,
        SEVENTH = 7,
        EIGHTH = 8
    };

}


#endif //MAHJONG_ENUMS_H
