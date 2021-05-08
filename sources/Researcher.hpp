#pragma once
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"

namespace pandemic{
    class Researcher : public Player
    {
        public:
        using Player::Player;
        //Researcher();
        ~Researcher();
        Player& discover_cure(Color c,int n=CARDS_NEEDED) override;
        Researcher(Board & b, City c): Player(b,c){
            this->r= "Researcher";
        }
    };
}