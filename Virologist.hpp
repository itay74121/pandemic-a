#pragma once
#include "Player.hpp"

namespace pandemic{
    class Virologist : public Player
    {
        public:
        using Player::Player;
        // Virologist();
        ~Virologist();
    };
}