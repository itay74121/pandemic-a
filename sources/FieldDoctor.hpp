#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
namespace pandemic{
    class FieldDoctor : public Player
    {
        public:
        using Player::Player;
        //FieldDoctor();
        ~FieldDoctor();
        Player& treat(City c) override;
        FieldDoctor(Board & b, City c): Player(b,c){
            this->r= "FieldDoctor";
        }
    };
}