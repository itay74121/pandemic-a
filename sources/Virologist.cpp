#include "Player.hpp"
#include "Virologist.hpp"
#include "City.hpp"
#include <stdexcept>
#include "Board.hpp"

using namespace std;

namespace pandemic
{
    Virologist::~Virologist()
    {

    }
    Player& Virologist::treat(City c)
    {
        if((*this->b)[c] > 0)
        {
            if(this->c != c)
            {
                if(check_card(c))
                {
                    throw_card(c);
                }
                else
                {
                    throw logic_error("No card");
                }
            }
            if(this->b->get_color_medicine(this->b->get_city(c).color))
            {
                this->b->get_city(c).diseasepoints = 0;
            }
            else
            {
                this->b->get_city(c).diseasepoints -= 1;
            }
        }
        else
        {
            throw logic_error("Cant treat the city!");
        }
        return *this;
    }
}