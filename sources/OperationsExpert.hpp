#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{
    class OperationsExpert : public Player
    {
        public:
        using Player::Player;
        //OperationsExpert();
        ~OperationsExpert();
        Player& build() override;
        OperationsExpert(Board & b, City c): Player(b,c){
            this->r= "OperationsExpert";
        }
    };
}