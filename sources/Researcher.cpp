#include "Player.hpp"
#include "Researcher.hpp"
#include "Color.hpp"
#include <vector>

using namespace std;
namespace pandemic
{
    Researcher::~Researcher()
    {

    }
    Player& Researcher::discover_cure(Color c,int n)
    {
        if(this->b->get_color_medicine(c))
        {
            return *this;
        }
        int count =0;
        vector<City> temp;
        for(size_t i = 0; count !=CARDS_NEEDED && i < this->cards.size();i++)
        {
            City city = this->cards.at(i);
            if(this->b->get_city(city).color == c)
            {
                count += 1;
                temp.push_back(city);
            } 
        }
        if(count == n)
        {
            // something
            for (size_t j = 0; j < CARDS_NEEDED; j++)
            {
                throw_card(temp.at(j));
            }
            this->b->get_color_medicine(c) = true;
        }
        else
        {
            throw logic_error("Cant discover cure there are not enough cards");
        }
        return *(this);
    }
}