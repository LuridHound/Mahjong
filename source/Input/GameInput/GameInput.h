#ifndef MAHJONG_GAMEINPUT_H
#define MAHJONG_GAMEINPUT_H


#include <Input/Input.h>


//
//
class GameInput final : public Input
{
    public :

        virtual void update(Enums::Stage& stage, User& user, Geometry& geometry, sf::Event* event) final;
};


#endif //MAHJONG_GAMEINPUT_H
