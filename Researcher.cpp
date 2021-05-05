#include "Player.hpp"
#include "Researcher.hpp"
#include "Color.hpp"
namespace pandemic
{
    Researcher::~Researcher()
    {

    }
    Player& Researcher::discover_cure(Color c)
    {
        return *this;
    }
}