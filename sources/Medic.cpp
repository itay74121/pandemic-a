
#include "Player.hpp"
#include "Medic.hpp"
#include <stdexcept>
using namespace std;
namespace pandemic
{
    Medic::~Medic()
    {

    }
    Player& Medic::drive(City c) 
    {
        Player::drive(c);
        if( this->b->get_color_medicine(this->b->get_city(c).color))
        {
            this->b->get_city(c).diseasepoints = 0;
        }
        return *this;
    }
    Player& Medic::fly_direct(City c)
    {
        Player::fly_direct(c);
        if( this->b->get_color_medicine(this->b->get_city(c).color))
        {
            this->b->get_city(c).diseasepoints = 0;
        }
        return *this;
    }
    Player& Medic::fly_shuttle(City c)
    {
        Player::fly_shuttle(c);
        if( this->b->get_color_medicine(this->b->get_city(c).color))
        {
            this->b->get_city(c).diseasepoints = 0;
        }
        return *this;
    }
    Player& Medic::fly_charter(City c)
    {
        Player::fly_charter(c);
        if( this->b->get_color_medicine(this->b->get_city(c).color))
        {
            this->b->get_city(c).diseasepoints = 0;
        }
        return *this;
    }
    Player& Medic::treat(City c) 
    {
        if(c == this->c && (*this->b)[c] > 0)
        {
            this->b->get_city(c).diseasepoints=0;
        }
        else
        {
            throw logic_error("Cant treat the city!");
        }
        return *this;
    }
}