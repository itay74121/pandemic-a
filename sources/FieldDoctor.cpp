#include "Player.hpp"
#include "FieldDoctor.hpp"
#include "City.hpp"
#include <stdexcept>
#include <algorithm>

using namespace std;

namespace pandemic
{
    FieldDoctor::~FieldDoctor()
    {

    }
    Player& FieldDoctor::treat(City c)
    {
        vector<City>& temp = this->b->get_city(this->c).connections;
        if((c == this->c || find(temp.begin(),temp.end(),c)!=temp.end())&& (*this->b)[c] > 0)
        {
            Color color = this->b->get_city(c).color;
            if(this->b->get_color_medicine(color))
            {
                this->b->get_city(c).diseasepoints = 0;
            }
            else
            {
                this->b->get_city(c).diseasepoints -=1;
            }
        }
        else
        {
            throw logic_error("Cant treat the city!");
        }
        return *(this);
    }
}