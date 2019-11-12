#ifndef MAHJONG_USER_H
#define MAHJONG_USER_H


#include "../Input/Input.h"
#include "../Rune/Rune.h"

#include "../Geometry/Geometry.h"
#include "../GameObject/GameObject.h"

class Input;

//
//
class User final : public GameObject
{
    public :
        User();

        virtual void respondEvent() final;

        void update(Enums::Stage& stage, Geometry* geometry);

        void setInput(Input* input_);

        void setRune(Rune* rune);

        void setLevel(const Enums::UserChoice level);

        Enums::UserChoice levelChoice();

        void clear();

    private :
        std::unique_ptr<Input> input;

        Enums::UserChoice choice;

        Rune* first;
        Rune* second;
};


#endif //MAHJONG_USER_H
