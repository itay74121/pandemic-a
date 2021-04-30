#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <string>
#include "Board.hpp"

namespace pandemic
{
    class Player
    {
        Board * b;
        City c;
        std::string r;
        public:
        Player(Board & b, City c);
        Player(Board & b, City c,int cards);
        Player& drive(City c);
        Player& fly_direct(City c);
        Player& fly_charter(City c);
        Player& fly_shuttle(City c);
        Player& build();
        Player& discover_cure(Color c);
        Player& treat(City c);
        std::string role();
        Player& take_card(City c);
    };
}