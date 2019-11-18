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

        void update(Enums::Stage& stage, Geometry& geometry);

        void setInput(std::unique_ptr<Input> input_);

        void setRune(std::shared_ptr<Rune>& rune);

        void setLevel(const Enums::UserChoice level);

        [[nodiscard]]
        Enums::UserChoice levelChoice();

        void clear();

    private :

        Enums::UserChoice choice;

        std::unique_ptr<Input> input;

        std::shared_ptr<Rune> first;
        std::shared_ptr<Rune> second;
};


#endif //MAHJONG_USER_H
