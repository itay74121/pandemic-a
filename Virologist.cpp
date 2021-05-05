#include "Player.hpp"
#include "Virologist.hpp"
#include "City.hpp"

namespace pandemic
{
    Virologist::~Virologist()
    {

    }
    Player& Virologist::treat(City c)
    {
        return *this;
    }
}