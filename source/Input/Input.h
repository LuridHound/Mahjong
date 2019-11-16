#ifndef MAHJONG_INPUT_H
#define MAHJONG_INPUT_H


#include "../Enums.h"
#include "../User/User.h"
#include "../Geometry/Geometry.h"


class User;


//
//
class Input
{
    public :

        virtual void update(Enums::Stage& stage, User* user, Geometry* geometry, sf::Event* event) = 0;
};


#endif //MAHJONG_INPUT_H
