#pragma once
#include "Player.hpp"

namespace pandemic{
    class OperationsExpert : public Player
    {
        public:
        using Player::Player;
        //OperationsExpert();
        ~OperationsExpert();
        Player& build() override;
        
    };
}