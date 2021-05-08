#include "Player.hpp"
#include "Dispatcher.hpp"
#include "City.hpp"
#include <stdexcept>

namespace pandemic
{
    Dispatcher::~Dispatcher()
    {

    }
    Player & Dispatcher::fly_direct(City c)
    {
        if(this->c == c)
        {
            throw std::logic_error("Cant fly to city from itself");
        }
        if(this->b->get_city(this->c).station)
        {
            this->c = c;
        }
        else
        {
            if(check_card(c))
            {
                throw_card(c);
                this->c = c;
            }
            else
            {
                throw std::logic_error("Cant fly direct to there!\n you don't have the card and this is not a research station");
            }
        }
        return *this;
    }
}