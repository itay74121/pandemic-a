#pragma once
#include "Player.hpp"

namespace pandemic{
    class Dispatcher : public Player
    {
        public:
        //Dispatcher(Board & b,City c);
        ~Dispatcher();
        using Player::Player;
        Player& fly_direct(City c) override;
    };
}