#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <string>
#include "Board.hpp"
#include <vector>

namespace pandemic
{
    class Player
    {
        protected:
        Board * b;
        City c;
        std::string r;
        std::vector<City> cards;
        void insert_card(City c);
        bool check_card(City c);
        void throw_card(City c);
        public:
        Player(Board & b, City c);
        Player(Board & b, City c,int cards);
        virtual Player& drive(City c);
        virtual Player& fly_direct(City c);
        virtual Player& fly_charter(City c);
        virtual Player& fly_shuttle(City c);
        virtual Player& build();
        virtual Player& discover_cure(Color c,int n =CARDS_NEEDED);
        virtual Player& treat(City c);
        virtual std::string role();
        Player& take_card(City c);
        City getcity(){return this->c;};
    };
}