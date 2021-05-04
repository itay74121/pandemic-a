#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{
    class Scientist : public Player
    {
        public:
        uint n;
        using Player::Player;
        Scientist(Board & b,City c,uint n);
        ~Scientist();
    };
}