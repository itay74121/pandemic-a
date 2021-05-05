#pragma once
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{
    class Virologist : public Player
    {
        public:
        using Player::Player;
        // Virologist();
        ~Virologist();
        Player&  treat(City c) override;
    };
}