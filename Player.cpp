#include "Player.hpp"


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