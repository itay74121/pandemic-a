#include "Board.hpp"
#include <ostream>
#include "City.hpp"
namespace pandemic 
{
    int & Board::operator [] (City c)
    {
        return this->CitytoDisease[c];
    }
    bool Board::is_clean()
    {
        for(int i = 0; i < 48;i++)
        {
            City city = (City)i;
            if(0<this->CitytoDisease[city])
            {
                return false;
            }
        }
        return true;
    }
    std::ostream& operator<< (std::ostream& os, const Board& dt)
    {
        return os;
    }
}

