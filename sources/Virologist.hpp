#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"

namespace pandemic{
    class Virologist : public Player
    {
        public:
        using Player::Player;
        // Virologist();
        ~Virologist();
        Player&  treat(City c) override;
        Virologist(Board & b, City c): Player(b,c){
            this->r= "Virologist";
        }
    };
}