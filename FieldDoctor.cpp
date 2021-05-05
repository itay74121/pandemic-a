#include "Player.hpp"
#include "FieldDoctor.hpp"
#include "City.hpp"

namespace pandemic
{
    FieldDoctor::~FieldDoctor()
    {

    }
    Player& FieldDoctor::treat(City c)
    {
        return *this;
    }
}