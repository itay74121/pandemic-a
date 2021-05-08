#include "Player.hpp"
#include <stdexcept>
#include "Board.hpp"
#include <algorithm>
using namespace std;

namespace pandemic
{
    Player::Player(Board& b,City c)
    {
        this->b = &b;
        this->c = c;
    }
    Player::Player(Board& b, City c,int cards)
    {
        this->b = &b;
        this->c = c;
        for(int i = 0;i>=0&&i<cards;i++)
        {
            take_card(c);
        }
    }
    void Player::insert_card(City c)
    {
        //uint ca = this->check_card(c);
        this->cards.push_back(c);
    }
    /**
     * Check if a card is in the cards map.
    */
    bool Player::check_card(City c)
    {
        return find(this->cards.begin(),this->cards.end(),c) != this->cards.end();
    }
    void Player::throw_card(City c)
    {
        if (check_card(c))
        {
            this->cards.erase(find(this->cards.begin(),this->cards.end(),c));
            //std::remove(this->cards.begin(),this->cards.end(),c);
            this->b->get_city(c).card = true;
        }
        else
        {
            throw std::logic_error("No card: "+pandemic::City_::citytos(c)+" to throw for player: "+this->role());
        }
    }

    Player& Player::build()
    {
        if(!this->b->get_city(c).station)
        {
            if(check_card(this->c))
            {
                throw_card(c);
                this->b->get_city(c).station = true;
            }
            else
            {
                throw logic_error("cant build research facility without city card");
            }
        }
        return *(this);
    }
    Player& Player::drive(City c)
    {
        vector<City> & temp = this->b->get_city(this->c).connections;
        if(find(temp.begin(),temp.end(),c) == temp.end())
        {
            throw logic_error("Cant drive to that city"+pandemic::City_::citytos(c)+"since player doesn't have the card");
        }
        this->c = c;
        return *(this);
    }
    Player& Player::fly_direct(City c)
    {
        bool flag = false;
        if(this->c == c)
        {
            flag =true;
        }
        if(check_card(c) && !flag)
        {
            throw_card(c);
            this->c = c;
        }
        else
        {
            throw logic_error("Cant fly direct to that city "+pandemic::City_::citytos(c)+" since player doesn't have the card");
        }
        return *(this);
    }
    Player& Player::fly_charter(City c)
    {
        bool flag = false;
        if(this->c == c)
        {
            flag =true;
        }
        if(check_card(this->c) && !flag)
        {
            throw_card(this->c);
            this->c = c;
        }
        else
        {
            throw logic_error("Cant fly direct to that city "+pandemic::City_::citytos(c)+" since player doesn't have the card");
        }
        return *(this);
    }
    Player& Player::fly_shuttle(City c)
    {
        bool flag = false;
        if(this->c == c)
        {
            flag =true;
        }
        if( !flag && this->b->get_city(this->c).station && this->b->get_city(c).station)
        {
            this->c = c;
        }
        else
        {
            throw logic_error("Cant fly shuttle between those cities since one of them doesn't have any research facility");
        }
        return *(this);
    }
    Player& Player::discover_cure(Color c,int n)
    {
        if(this->b->get_color_medicine(c))
        {
            return *this;
        }
        if(!this->b->get_city(this->c).station)
        {
            throw logic_error("This city does not have a research facility");
        }
        int count =0;
        vector<City> temp;
        for(size_t i = 0; count !=n && i < this->cards.size();i++)
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
            for (size_t j = 0; j < n; j++)
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
    Player& Player::treat(City c)
    {
        if(c == this->c && (*this->b)[c] > 0)
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
    std::string Player::role()
    {
        return this->r;
    }
    Player& Player::take_card(City c)
    {
        // if(this->b->get_city(c).card == true)
        // {
            this->b->get_city(c).card = false;
            this->insert_card(c);
        //}
        return *(this);
    }
}