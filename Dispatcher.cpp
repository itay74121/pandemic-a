#include "Player.hpp"
#include "Dispatcher.hpp"
#include "City.hpp"

namespace pandemic
{
    Dispatcher::~Dispatcher()
    {

    }
    Player & Dispatcher::fly_direct(City c)
    {
        return *this;
    }
}