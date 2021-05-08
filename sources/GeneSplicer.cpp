
#include "Player.hpp"
#include "GeneSplicer.hpp"
#include <stdexcept>
using namespace std;

namespace pandemic
{
    // GeneSplicer::GeneSplicer()
    // {

    // }
    GeneSplicer::~GeneSplicer()
    {

    }
    Player& GeneSplicer::discover_cure(Color c,int n)
    {
        if(this->b->get_color_medicine(c))
        {
            return *this;
        }
        if(!this->b->get_city(this->c).station)
        {
            throw logic_error("This city does not have a research facility");
        }
        if(this->cards.size()>=n)
        {
            for(size_t i =0;i<n;i++)
            {
                City card = cards.at(cards.size()-1);
                throw_card(card);
            }
        }
        else
        {
            throw logic_error("Cant discover cure there are not enough cards");
        }
        return *(this);
    }
}