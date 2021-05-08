#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
namespace pandemic{
    class Dispatcher : public Player
    {
        public:
        //Dispatcher(Board & b,City c);
        ~Dispatcher();
        using Player::Player;
        Player& fly_direct(City c) override;
        Dispatcher(Board & b, City c): Player(b,c){
            this->r= "Dispatcher";
        }
    };
}