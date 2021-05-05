
#include "Player.hpp"
#include "Medic.hpp"
namespace pandemic
{
    Medic::~Medic()
    {

    }
    Player& Medic::drive(City c) 
    {
        return *this;
    }
    Player& Medic::treat(City c) 
    {
        return *this;
    }
}