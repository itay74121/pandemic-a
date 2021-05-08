#include "Board.hpp"
#include <ostream>
#include "City.hpp"
#include <string>
using namespace std;

namespace pandemic 
{

    int & Board::operator [] (City c)
    {
        return this->map.at(c).diseasepoints;
    }
    bool Board::is_clean()
    {
        for(int i = 0; i < CARDS_TOTAL;i++)
        {
            City city = (City)i;
            if ((*this)[city] != 0)
            {
                return false;
            }
        }
        return true;
    }
    std::ostream& operator<< (std::ostream& os,  Board& b) 
    {
        for(int i = 0; i<CARDS_TOTAL;i++)
        {
            City c = (City) i;
            os << pandemic::City_::citytos(c) << ": " << b[c] << " ";
            if(i!=0 && i%CARDS_NEEDED == 0)
            {
                os << endl;
            }
        }
        os << endl;
        return os;
    }
}

