#pragma once
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{
    class Medic : public Player
    {
        public:
        using Player::Player;
        //Medic();
        ~Medic();
        Player& drive(City c) override;
        Player& treat(City c) override;
    };
}