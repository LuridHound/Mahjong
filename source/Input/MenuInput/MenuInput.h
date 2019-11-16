#ifndef MAHJONG_MENUINPUT_H
#define MAHJONG_MENUINPUT_H


#include "../Input.h"


//
//
class MenuInput final : public Input
{
    public :

        virtual void update(Enums::Stage& stage, User* user, Geometry* geometry, sf::Event* event) final;
};


#endif //MAHJONG_MENUINPUT_H
