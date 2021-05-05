#include "Player.hpp"
#include "OperationsExpert.hpp"

namespace pandemic
{
    OperationsExpert::~OperationsExpert()
    {

    }
    Player& OperationsExpert::build()
    {
        return *this;
    }
}