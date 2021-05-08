#include "Player.hpp"
#include "Scientist.hpp"
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
namespace pandemic
{
    Scientist::~Scientist()
    {

    }
    Scientist::Scientist(Board & b, City c,int n) : Player(b,c)
    {
        this->r = "Scientist";
        this->n = n;
    }
    Player& Scientist::discover_cure(Color c,int n)
    {
        Player::discover_cure(c,this->n);
        return  *this;
    }
}