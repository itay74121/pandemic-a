#pragma once
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"

namespace pandemic{
    class GeneSplicer : public Player
    {
        public:
        using Player::Player;
        //GeneSplicer();
        ~GeneSplicer();
        Player& discover_cure(Color c,int n=CARDS_NEEDED) override;
        GeneSplicer(Board & b, City c): Player(b,c){
            this->r= "GeneSplicer";
        }
    };
}