#pragma once
#include "Player.hpp"

namespace pandemic{
    class Researcher : public Player
    {
        public:
        using Player::Player;
        //Researcher();
        ~Researcher();
    };
}