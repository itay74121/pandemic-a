#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

Board * b;
Researcher * researcher;
Scientist * scientist;
FieldDoctor * fielddoctor;
GeneSplicer * genesplicer;
OperationsExpert * operationsexpert;
Dispatcher * dispatcher;
Medic * medic;
Virologist * virologist;

void init()
{
    b = new Board();
    researcher = new Researcher(*b,City::Algiers);
    scientist = new Scientist(*b,City::Algiers,4);
    fielddoctor = new FieldDoctor(*b,City::Algiers);
    genesplicer = new GeneSplicer(*b,City::Algiers);
    operationsexpert = new OperationsExpert(*b,City::Algiers);
    dispatcher = new Dispatcher(*b,City::Algiers);
    medic = new Medic(*b,City::Algiers);
    virologist = new Virologist(*b,City::Algiers);
}
void _init()
{
    delete b;
    delete researcher;
    delete scientist;
    delete fielddoctor;
    delete genesplicer;
    delete operationsexpert;
    delete dispatcher;
    delete medic;
    delete virologist;
}

void take_all_cards(Player & p)
{
    for(int i = 0;i < 48;i++)
    {
        p.take_card(City::Algiers);
    }
}


// TEST_CASE("test Board init and methods")
// {
//     init();
//     for(int i =0; i < 48;i++)
//     {
//         City c = (City)i;
//         CHECK(b->getCitytoDisease()[c] == 0);
//         CHECK(b->getCitytoStation()[c]==false);
//     }
//     CHECK(b->getColortoVaccine()[Red]==false);
//     CHECK(b->getColortoVaccine()[Yellow]==false);
//     CHECK(b->getColortoVaccine()[Black]==false);
//     CHECK(b->getColortoVaccine()[Blue]==false);
//     CHECK(b->is_clean() == true);
//     _init();
// }


TEST_CASE("discover cure")
{
    init();
    
    _init();
}

TEST_CASE("test no throw")
{
    init();
    CHECK_NOTHROW(researcher->discover_cure(Red));
    CHECK_NOTHROW(researcher->discover_cure(Red));
    CHECK_NOTHROW(researcher->discover_cure(Yellow));
    CHECK_NOTHROW(researcher->discover_cure(Yellow));
    CHECK_NOTHROW(researcher->discover_cure(Blue));
    CHECK_NOTHROW(researcher->discover_cure(Blue));
    CHECK_NOTHROW(researcher->discover_cure(Black));
    CHECK_NOTHROW(researcher->discover_cure(Black));
    CHECK_NOTHROW(researcher->drive(Madrid));
    CHECK_NOTHROW(researcher->drive(Paris));
    CHECK_NOTHROW(researcher->drive(Istanbul));
    CHECK_NOTHROW(researcher->drive(Cairo));

    _init();
}



TEST_CASE("test throw drive")
{
    init();
    CHECK_THROWS(researcher->drive(London));
    CHECK_THROWS(researcher->drive(Lagos));
    CHECK_THROWS(researcher->drive(SaoPaulo));
    CHECK_THROWS(researcher->drive(NewYork));
    _init();
}

TEST_CASE("test throw fly")
{
    init();
    CHECK_THROWS(researcher->fly_direct(London));
    CHECK_THROWS(researcher->fly_direct(Lagos));
    CHECK_THROWS(researcher->fly_direct(SaoPaulo));
    CHECK_THROWS(researcher->fly_direct(NewYork));
    CHECK_THROWS(researcher->fly_charter(London));
    CHECK_THROWS(researcher->fly_charter(Lagos));
    CHECK_THROWS(researcher->fly_charter(SaoPaulo));
    CHECK_THROWS(researcher->fly_charter(NewYork));
    operationsexpert->build();
    // not possible since new york doesn't have any reseach station
    CHECK_THROWS(operationsexpert->fly_shuttle(NewYork));
    _init();
}

TEST_CASE("check abilities of OperationsExpert")
{
    init();
    CHECK_NOTHROW(operationsexpert->build());
    CHECK_NOTHROW(operationsexpert->drive(Paris));
    CHECK_NOTHROW(operationsexpert->build());
    CHECK_NOTHROW(operationsexpert->drive(London));
    CHECK_NOTHROW(operationsexpert->build());
    CHECK_THROWS(operationsexpert->build());
    _init();
}

TEST_CASE("check abilities of Dispatcher")
{
    init();
    operationsexpert->build();
    CHECK_NOTHROW(dispatcher->fly_direct(SaoPaulo));
    CHECK_THROWS(dispatcher->fly_direct(Algiers));
    CHECK_THROWS(dispatcher->fly_direct(Miami));
    _init();
}
TEST_CASE("check abilities of Scientist")
{ 
    init();
    operationsexpert->build();
    scientist->take_card(Algiers).take_card(Algiers).take_card(Algiers).take_card(Algiers);
    CHECK_NOTHROW(scientist->discover_cure(Red));
    scientist->take_card(Algiers).take_card(Algiers).take_card(Algiers).take_card(Algiers);
    CHECK_NOTHROW(scientist->discover_cure(Red));
    CHECK_THROWS(scientist->discover_cure(Red));
    _init();
}

TEST_CASE("check abilities of Researcher")
{ 
    init();
    take_all_cards((Player &)researcher);
    CHECK_NOTHROW(researcher->discover_cure(Red));
    

    _init();
}

