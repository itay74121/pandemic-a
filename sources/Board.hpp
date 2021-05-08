#pragma once 
#include "City.hpp"
#include "Color.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

namespace pandemic
{
    class City_
    {
        public:
        std::vector<City> connections;
        Color color;
        int diseasepoints;
        bool station;
        bool card;
        City city;
        static Color stocolor(std::string c)
        {
            if ("Red" == c)
            {   
                return Red;
            }
            if("Blue" == c)
            {
                return Blue;
            }
            if("Yellow" == c)
            {
                return Yellow;
            }
            if("Black" == c)
            {
                return Black;
            }
            else
            {
                return NoColor;
            }
        }
        static City stocity(std::string cityname)
        {
            if ("Algiers" == cityname){
                return Algiers;
            }
            if ("Atlanta" == cityname){
                return Atlanta;
            }
            if ("Baghdad" == cityname){
                return Baghdad;
            }
            if ("Bangkok" == cityname){
                return Bangkok;
            }
            if ("Beijing" == cityname){
                return Beijing;
            }
            if ("Bogota" == cityname){
                return Bogota;
            }
            if ("BuenosAires" == cityname){
                return BuenosAires;
            }
            if ("Cairo" == cityname){
                return Cairo;
            }
            if ("Chennai" == cityname){
                return Chennai;
            }
            if ("Chicago" == cityname){
                return Chicago;
            }
            if ("Delhi" == cityname){
                return Delhi;
            }
            if ("Essen" == cityname){
                return Essen;
            }
            if ("HoChiMinhCity" == cityname){
                return HoChiMinhCity;
            }
            if ("HongKong" == cityname){
                return HongKong;
            }
            if ("Istanbul" == cityname){
                return Istanbul;
            }
            if ("Jakarta" == cityname){
                return Jakarta;
            }
            if ("Johannesburg" == cityname){
                return Johannesburg;
            }
            if ("Karachi" == cityname){
                return Karachi;
            }
            if ("Khartoum" == cityname){
                return Khartoum;
            }
            if ("Kinshasa" == cityname){
                return Kinshasa;
            }
            if ("Kolkata" == cityname){
                return Kolkata;
            }
            if ("Lagos" == cityname){
                return Lagos;
            }
            if ("Lima" == cityname){
                return Lima;
            }
            if ("London" == cityname){
                return London;
            }
            if ("LosAngeles" == cityname){
                return LosAngeles;
            }
            if ("Madrid" == cityname){
                return Madrid;
            }
            if ("Manila" == cityname){
                return Manila;
            }
            if ("MexicoCity" == cityname){
                return MexicoCity;
            }
            if ("Miami" == cityname){
                return Miami;
            }
            if ("Milan" == cityname){
                return Milan;
            }
            if ("Montreal" == cityname){
                return Montreal;
            }
            if ("Moscow" == cityname){
                return Moscow;
            }
            if ("Mumbai" == cityname){
                return Mumbai;
            }
            if ("NewYork" == cityname){
                return NewYork;
            }
            if ("Osaka" == cityname){
                return Osaka;
            }
            if ("Paris" == cityname){
                return Paris;
            }
            if ("Riyadh" == cityname){
                return Riyadh;
            }
            if ("SanFrancisco" == cityname){
                return SanFrancisco;
            }
            if ("Santiago" == cityname){
                return Santiago;
            }
            if ("SaoPaulo" == cityname){
                return SaoPaulo;
            }
            if ("Seoul" == cityname){
                return Seoul;
            }
            if ("Shanghai" == cityname){
                return Shanghai;
            }
            if ("StPetersburg" == cityname){
                return StPetersburg;
            }
            if ("Sydney" == cityname){
                return Sydney;
            }
            if ("Taipei" == cityname){
                return Taipei;
            }
            if ("Tehran" == cityname){
                return Tehran;
            }
            if ("Tokyo" == cityname){
                return Tokyo;
            }
            if ("Washington" == cityname){
                return Washington;
            }
            else
            {
                return NoCity;
            }
        }   
        static std::string citytos(City city)
        {
            if(city == Algiers){
                return "Algiers";
            }
            if(city == Atlanta){
                return "Atlanta";
            }
            if(city == Baghdad){
                return "Baghdad";
            }
            if(city == Bangkok){
                return "Bangkok";
            }
            if(city == Beijing){
                return "Beijing";
            }
            if(city == Bogota){
                return "Bogota";
            }
            if(city == BuenosAires){
                return "BuenosAires";
            }
            if(city == Cairo){
                return "Cairo";
            }
            if(city == Chennai){
                return "Chennai";
            }
            if(city == Chicago){
                return "Chicago";
            }
            if(city == Delhi){
                return "Delhi";
            }
            if(city == Essen){
                return "Essen";
            }
            if(city == HoChiMinhCity){
                return "HoChiMinhCity";
            }
            if(city == HongKong){
                return "HongKong";
            }
            if(city == Istanbul){
                return "Istanbul";
            }
            if(city == Jakarta){
                return "Jakarta";
            }
            if(city == Johannesburg){
                return "Johannesburg";
            }
            if(city == Karachi){
                return "Karachi";
            }
            if(city == Khartoum){
                return "Khartoum";
            }
            if(city == Kinshasa){
                return "Kinshasa";
            }
            if(city == Kolkata){
                return "Kolkata";
            }
            if(city == Lagos){
                return "Lagos";
            }
            if(city == Lima){
                return "Lima";
            }
            if(city == London){
                return "London";
            }
            if(city == LosAngeles){
                return "LosAngeles";
            }
            if(city == Madrid){
                return "Madrid";
            }
            if(city == Manila){
                return "Manila";
            }
            if(city == MexicoCity){
                return "MexicoCity";
            }
            if(city == Miami){
                return "Miami";
            }
            if(city == Milan){
                return "Milan";
            }
            if(city == Montreal){
                return "Montreal";
            }
            if(city == Moscow){
                return "Moscow";
            }
            if(city == Mumbai){
                return "Mumbai";
            }
            if(city == NewYork){
                return "NewYork";
            }
            if(city == Osaka){
                return "Osaka";
            }
            if(city == Paris){
                return "Paris";
            }
            if(city == Riyadh){
                return "Riyadh";
            }
            if(city == SanFrancisco){
                return "SanFrancisco";
            }
            if(city == Santiago){
                return "Santiago";
            }
            if(city == SaoPaulo){
                return "SaoPaulo";
            }
            if(city == Seoul){
                return "Seoul";
            }
            if(city == Shanghai){
                return "Shanghai";
            }
            if(city == StPetersburg){
                return "StPetersburg";
            }
            if(city == Sydney){
                return "Sydney";
            }
            if(city == Taipei){
                return "Taipei";
            }
            if(city == Tehran){
                return "Tehran";
            }
            if(city == Tokyo){
                return "Tokyo";
            }
            if(city == Washington){
                return "Washington";
            }
            else
            {
                return "NoCity";
            }
        }
        City_(std::string cityname,std::string color,std::vector<std::string> cities)
        {
            this->city = stocity(cityname);
            this->color = stocolor(color);
            for(int i =0;i<cities.size();i++)
            {
                connections.push_back(stocity(cities.at((size_t)i)));
            }
            this->station = false;
            this->card = true;
            this->diseasepoints = 0;
        } 
        City_(const City_ & other)
        {
            this->color = other.color;
            this->diseasepoints = other.diseasepoints;
            this->card = other.card;
            this->city = other.city;
            this->station = other.station;
            for(size_t i = 0;i<other.connections.size();i++)
            {
                this->connections.push_back(other.connections.at(i));
            }
        }
        City_()
        {
            this->city = NoCity;
            this->color = NoColor;
            this->station = false;
            this->card = true;
            this->diseasepoints = 0;
        }
        void init(std::string cityname,std::string color,std::vector<std::string> cities)
        {
            this->city = stocity(cityname);
            this->color = stocolor(color);
            for(int i =0;i<cities.size();i++)
            {
                connections.push_back(stocity(cities.at((size_t)i)));
            }
            this->station = false;
            this->card = true;
        }
    };
    class Board
    {   
        private:   
        std::vector<City_> map{CARDS_TOTAL};
        bool colors_medicine[4];
        public:
        Board()
        {
            remove_cures();
            std::ifstream s;
            s.open("cities_map.txt",std::ios::in);  
            std::string line;
            while(std::getline(s,line))
            {
                std::stringstream str {line};
                std::string city,color,t;
                std::vector<std::string> temp;
                str >> city >> color;
                while(!str.eof())
                {
                    str >> t;
                    temp.push_back(t);
                }
                //City_ c (city,color,temp);
                City c = City_::stocity(city);
                map.at(c).init(city,color,temp);
            }
        }
        int & operator [] (City c);
        bool is_clean();
        friend std::ostream& operator <<(std::ostream& os, Board& b);
        City_ & get_city(City c)
        {
            return map.at(c);
        }
        bool & get_color_medicine(Color c)
        {
            return colors_medicine[c];
        }
        void remove_cures()
        {
            for(int i = 0; i<4;i++)
            {
                colors_medicine[i] = false;
            }
        }
    };
}