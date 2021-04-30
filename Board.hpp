#pragma once 
#include <unordered_map>
#include "City.hpp"
#include "Color.hpp"
#include <ostream>

namespace pandemic
{
    class Board
    {      
        std::unordered_map<City, int> CitytoDisease;
        std::unordered_map<City, bool> CitytoStation;
        std::unordered_map<Color, bool> ColortoVaccine;
        public:
        Board()
        {
            // init citytodisease
            for(City c = Johannesburg;c<=Sydney;++c)
            {
                CitytoDisease[c] =0;
                CitytoStation[c] =false;
            } 
            ColortoVaccine[Red]=false;
            ColortoVaccine[Black]=false;
            ColortoVaccine[Yellow]=false;
            ColortoVaccine[Blue]=false;

        }
        int & operator [] (City c);
        bool is_clean();
        friend std::ostream& operator <<(std::ostream& os, const Board& dt);

    };
}