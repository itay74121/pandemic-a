#pragma once
#include "Player.hpp"
#include "Color.hpp"
namespace pandemic{
    class Researcher : public Player
    {
        public:
        using Player::Player;
        //Researcher();
        ~Researcher();
        Player& discover_cure(Color c) override;
    };
}