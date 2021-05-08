#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Scientist : public Player
    {
        public:
        int n;
        //using Player::Player;
        Scientist(Board & b,City c,int n);
        ~Scientist();
        Player& discover_cure(Color c,int n = CARDS_NEEDED) override;
        Scientist(Board & b, City c): Player(b,c){
            this->r= "Scientist";
        }
    };
}