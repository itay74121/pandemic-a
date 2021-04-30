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
        for(City c = Johannesburg;c<=Sydney;++c)
        {
           if (CitytoDisease[c] > 0)
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

