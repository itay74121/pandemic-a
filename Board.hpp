#pragma once 
#include <unordered_map>
#include "City.hpp"
#include "Color.hpp"
#include <ostream>
#include <vector>

namespace pandemic
{
    class City_
    {
        private:
        std::vector<City> connections;
        Color color;
        uint diseasepoints;
        bool station;
        bool card;
        public:
        City_()
    };
    class Board
    {   
        private:   
        // std::unordered_map<City, int> CitytoDisease;
        int CitytoDisease [48];
        // std::unordered_map<City, bool> CitytoStation;
        bool CitytoStation[48];
        // std::unordered_map<Color, bool> ColortoVaccine;
        bool ColortoVaccine[4];
        // 
        int CitytoColor [48];

        public:
        Board()
        {
            // init citytodisease
            for(int i = 0; i < 48; i++)
            {
                City city = (City)i;
                CitytoDisease[city] =0;
                CitytoStation[city] =false;
            } 
            ColortoVaccine[Red]=false;
            ColortoVaccine[Black]=false;
            ColortoVaccine[Yellow]=false;
            ColortoVaccine[Blue]=false;
        }
        int & operator [] (City c);
        bool is_clean();
        friend std::ostream& operator <<(std::ostream& os, const Board& dt);
        std::unordered_map<City, int> getCitytoDisease()
        {return this->CitytoDisease;}
        std::unordered_map<City, bool> getCitytoStation()
        {return this->CitytoStation;}
        std::unordered_map<Color, bool> getColortoVaccine()
        {return this->ColortoVaccine;}
        void remove_cures()
        {
            
        }
    };
}