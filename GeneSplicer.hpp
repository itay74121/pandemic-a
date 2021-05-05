#pragma once
#include "Player.hpp"
#include "Color.hpp"

namespace pandemic{
    class GeneSplicer : public Player
    {
        public:
        using Player::Player;
        //GeneSplicer();
        ~GeneSplicer();
        Player& discover_cure(Color c) override;
    };
}