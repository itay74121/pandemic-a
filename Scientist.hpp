#pragma once
#include "Player.hpp"

namespace pandemic{
    class Scientist : public Player
    {
        public:
        using Player::Player;
        //Scientist();
        ~Scientist();
    };
}