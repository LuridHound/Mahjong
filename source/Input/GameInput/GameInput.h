#ifndef MAHJONG_GAMEINPUT_H
#define MAHJONG_GAMEINPUT_H


#include "../Input.h"


//
//
class GameInput final : public Input
{
    public :
        virtual void update(Enums::Stage& stage, User* user, Geometry* geometry) final;

};


#endif //MAHJONG_GAMEINPUT_H
