#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <string>
#include "Board.hpp"
#include <unordered_map>
#include <unordered_map>

namespace pandemic
{
    class Player
    {
        protected:
        Board * b;
        City c;
        std::string r;
        std::unordered_map<City,bool> cards;
        void insert_card(City c);
        bool check_card(City c);
        void throw_card(City c);
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