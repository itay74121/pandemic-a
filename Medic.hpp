#pragma once
#include "Player.hpp"

namespace pandemic{
    class Medic : public Player
    {
        public:
        using Player::Player;
        //Medic();
        ~Medic();
    };
}