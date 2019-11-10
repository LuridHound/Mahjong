#ifndef MAHJONG_ENUMS_H
#define MAHJONG_ENUMS_H

#include <cstddef>

namespace Enums
{
    enum class Stage : int
    {
        MENU = 0,
        GAME = 1
    };

    //  TODO
    //  Check typos.
    namespace Background {
        enum class Background : int {
            MENU = 0,
            FIRST_LEVEL = 1,
            SECOND_LEVEL = 2,
            THIRD_LEVEL = 3,
            FORTH_LEVEL = 4,
            FIFTH_LEVEL = 5,
            SIXTH_LEVEL = 6,
            SEVENTH_LEVEL = 7,
            EIGHT_LEVEL = 8
        };
        constexpr static size_t BACKGROUND_COUNT = 9u;
    }

}


#endif //MAHJONG_ENUMS_H
