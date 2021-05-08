#include "Player.hpp"
#include "OperationsExpert.hpp"

namespace pandemic
{
    OperationsExpert::~OperationsExpert()
    {

    }
    Player& OperationsExpert::build()
    {
        this->b->get_city(this->c).station = true;
        return *this;
    }
}