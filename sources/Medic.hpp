#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"

namespace pandemic{
    class Medic : public Player
    {
        public:
        using Player::Player;
        //Medic();
        ~Medic();
        Player& drive(City c) override;
        Player& fly_direct(City c) override;
        Player& fly_charter(City c) override;
        Player& fly_shuttle(City c) override;
        Player& treat(City c) override;
        Medic(Board & b, City c): Player(b,c){
            this->r= "Medic";
        }
    };
}