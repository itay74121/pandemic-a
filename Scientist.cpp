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
    Scientist::Scientist(Board & b, City c,uint n) : Player(b,c)
    {
        this->n = n;
    }
    Player& Scientist::discover_cure(Color c)
    {
        return  *this;
    }
}