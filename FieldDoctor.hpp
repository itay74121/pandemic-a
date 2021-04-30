#pragma once
#include "Player.hpp"

namespace pandemic{
    class FieldDoctor : public Player
    {
        public:
        using Player::Player;
        //FieldDoctor();
        ~FieldDoctor();
    };
}