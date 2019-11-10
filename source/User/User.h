#ifndef MAHJONG_USER_H
#define MAHJONG_USER_H


#include "../Input/Input.h"
#include "../Rune/Rune.h"

#include "../Geometry/Geometry.h"

class Input;

//
//
class User final
{
public :
        User();

        void update(Enums::Stage& stage, Geometry* geometry);

        void setInput(Input* input_);

        void setRune(Rune* rune);

        void setLevel(const Enums::UserChoice level);

        Enums::UserChoice levelChoice();

        void clear();
    private :
        Input* input;

        Enums::UserChoice choice;

        Rune* first;
        Rune* second;
};


#endif //MAHJONG_USER_H
