#pragma once
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{
    class FieldDoctor : public Player
    {
        public:
        using Player::Player;
        //FieldDoctor();
        ~FieldDoctor();
        Player& treat(City c) override;
    };
}