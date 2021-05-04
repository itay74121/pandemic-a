#include "Player.hpp"
#include <stdexcept>

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
        this->cards[c] = true;
    }
    bool Player::check_card(City c)
    {
        return this->cards.find(c) != this->cards.end();
    }
    void Player::throw_card(City c)
    {
        if (check_card(c))
        {
            if (this->cards[c] == true)
            {
                this->cards[c] = false;
            }
            else
            {
                throw std::logic_error("No cards of this type to throw");
            }
        }
    }

    Player& Player::build()
    {
        return *(this);
    }
    Player& Player::drive(City c)
    {
        return *(this);
    }
    Player& Player::fly_direct(City c)
    {
        return *(this);
    }
    Player& Player::fly_charter(City c)
    {
        return *(this);
    }
    Player& Player::fly_shuttle(City c)
    {
        return *(this);
    }
    Player& Player::discover_cure(Color c)
    {
        return *(this);
    }
    Player& Player::treat(City c)
    {
        return *(this);
    }
    std::string Player::role()
    {
        return this->r;
    }
    Player& Player::take_card(City c)
    {
        return *(this);
    }
}