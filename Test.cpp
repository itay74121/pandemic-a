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
        City c = (City) i;
        p.take_card(c);
    }
}



TEST_CASE("board init")
{
    init();
    for(int i = 0;i < 48;i++)
    {
        City c =  (City) i;
        CHECK((*b)[c] == 0);
    }
    CHECK(b->is_clean() == true);
    _init();
}

TEST_CASE("drive throw")
{
    init();
    CHECK_THROWS(researcher->drive(London));
    CHECK_THROWS(researcher->drive(Lagos));
    CHECK_THROWS(researcher->drive(SaoPaulo));
    CHECK_THROWS(researcher->drive(NewYork));
    _init();
}
TEST_CASE("drive no throw")
{
    init();
    CHECK_NOTHROW(researcher->drive(Madrid));
    CHECK_NOTHROW(researcher->drive(Paris));
    CHECK_NOTHROW(researcher->drive(Istanbul));
    CHECK_NOTHROW(researcher->drive(Cairo));
    _init();
}

TEST_CASE("fly direct no throw")
{
    init();
    medic->take_card(City::Baghdad);
    CHECK_NOTHROW(medic->fly_direct(City::Baghdad));
    operationsexpert->build();
    dispatcher->fly_direct(City::Baghdad);
    _init();
}
TEST_CASE("fly direct throw")
{
    init();
    CHECK_THROWS(medic->fly_direct(City::Baghdad));
    CHECK_THROWS(dispatcher->fly_direct(City::Baghdad));
    _init();
}

TEST_CASE("fly charter no throw")
{
    init();
    medic->take_card(City::Baghdad);
    CHECK_NOTHROW(medic->fly_charter(City::Baghdad));
    _init();
}
TEST_CASE("fly charter throw")
{
    init();
    CHECK_THROWS(medic->fly_charter(City::Baghdad));
    CHECK_THROWS(dispatcher->fly_charter(City::Baghdad));
    operationsexpert->build();
    CHECK_THROWS(dispatcher->fly_charter(City::Baghdad));
    _init();
}
TEST_CASE("fly shuttle no throw")
{
    init();
    operationsexpert->build();
    operationsexpert->drive(Madrid);
    operationsexpert->build();
    CHECK_NOTHROW(medic->fly_shuttle(Madrid));
    _init();
}

TEST_CASE("fly shuttle throw")
{
    init();
    CHECK_THROWS(medic->fly_shuttle(Madrid));
    operationsexpert->build();
    CHECK_THROWS(medic->fly_shuttle(Madrid));   
    operationsexpert->drive(Madrid);
    operationsexpert->build();
    medic->fly_shuttle(Madrid);
    medic->drive(London);
    CHECK_THROWS(medic->fly_shuttle(Madrid));   
    _init();
}


TEST_CASE("build no throw")
{
    init();
    medic->take_card(Algiers);
    CHECK_NOTHROW(medic->build());
    CHECK_NOTHROW(operationsexpert->build());  
    operationsexpert->take_card(Madrid);
    operationsexpert->drive(Madrid);
    CHECK_NOTHROW(operationsexpert->build());   
    _init();
}

TEST_CASE("build throw")
{
    init();
    CHECK_THROWS(medic->build());
    _init();
}


TEST_CASE("discover cure no throw")
{
    init();
    operationsexpert->build();
    medic->take_card(Beijing); // regular player 
    medic->take_card(Seoul);
    medic->take_card(Tokyo);
    medic->take_card(HongKong);
    medic->take_card(Shanghai);
    CHECK_NOTHROW(medic->discover_cure(Red));
    scientist->take_card(Algiers);// scientinst in reearch facility 
    scientist->take_card(Cairo);
    scientist->take_card(Riyadh);
    scientist->take_card(Baghdad);
    CHECK_NOTHROW(scientist->discover_cure(Red));
    researcher->take_card(Miami); // researcher in research facility 
    researcher->take_card(LosAngeles);
    researcher->take_card(Lima);
    researcher->take_card(SaoPaulo);
    researcher->take_card(Bogota);
    researcher->drive(Madrid);
    CHECK_NOTHROW(researcher->discover_cure(Yellow));
    researcher->take_card(Lagos); // researcher for the same color and with no reasearch facility 
    researcher->take_card(BuenosAires);
    researcher->take_card(Johannesburg);
    researcher->take_card(Khartoum);
    researcher->take_card(Santiago);
    CHECK_NOTHROW(researcher->discover_cure(Yellow));
    genesplicer->drive(Paris);
    genesplicer->take_card(Milan);
    genesplicer->take_card(Paris);
    genesplicer->take_card(Essen);
    genesplicer->take_card(StPetersburg);
    genesplicer->take_card(Karachi);
    CHECK_NOTHROW(genesplicer->discover_cure(Blue));

    
    _init();
}
TEST_CASE("discover cure  throw")
{
    init();
    medic->take_card(Beijing); // regular player not at research facility  
    medic->take_card(Seoul);
    medic->take_card(Tokyo);
    medic->take_card(HongKong);
    medic->take_card(Shanghai);
    CHECK_THROWS(medic->discover_cure(Red));
    operationsexpert->build();
    CHECK_THROWS(medic->discover_cure(Yellow)); // not the right color
    CHECK_THROWS(operationsexpert->discover_cure(Red)); // regular player at research facility without the right cards
    CHECK_THROWS(scientist->discover_cure(Red)); // scientist with no cards
    scientist->drive(Madrid);
    CHECK_THROWS(scientist->discover_cure(Red)); // scientist with no cards and no research facility 
    CHECK_THROWS(scientist->discover_cure(Yellow));  // not right color
    scientist->take_card(Algiers);// scientinst not in reearch facility with right cards
    scientist->take_card(Cairo);
    scientist->take_card(Riyadh);
    scientist->take_card(Baghdad);
    CHECK_THROWS(scientist->discover_cure(Red));
    // researcher in research facility with not enough cards
    researcher->take_card(LosAngeles);
    researcher->take_card(Lima);
    researcher->take_card(SaoPaulo);
    researcher->take_card(Bogota);
    CHECK_THROWS(researcher->discover_cure(Yellow));
    CHECK_THROWS(researcher->discover_cure(Black)); // not the right color 
    researcher->drive(Madrid); // same thing but not in research facility 
    CHECK_NOTHROW(scientist->discover_cure(Yellow));
    CHECK_NOTHROW(scientist->discover_cure(Blue));
    genesplicer->drive(Paris);
    genesplicer->take_card(Milan);
    genesplicer->take_card(Essen);
    genesplicer->take_card(StPetersburg);
    genesplicer->take_card(Karachi);
    CHECK_THROWS(genesplicer->discover_cure(Blue));
    _init();
}
TEST_CASE("treat no throw")
{
    init();
    (*b)[Algiers] = 5;
    CHECK_NOTHROW(operationsexpert->treat(Algiers));
    CHECK((*b)[Algiers] == 4);
    CHECK_NOTHROW(medic->treat(Algiers));
    CHECK((*b)[Algiers] == 0);
    operationsexpert->build();
    operationsexpert->take_card(Algiers);
    operationsexpert->take_card(Cairo);
    operationsexpert->take_card(Istanbul);
    operationsexpert->take_card(Baghdad);
    operationsexpert->take_card(Riyadh);
    operationsexpert->discover_cure(Black);
    (*b)[Algiers] = 5;
    CHECK_NOTHROW(operationsexpert->treat(Algiers));
    virologist->take_card(Miami);
    virologist->fly_direct(Miami);
    virologist->take_card(Paris);
    (*b)[Paris] = 5;
    CHECK_NOTHROW(virologist->treat(Paris));
    CHECK((*b)[Paris] == 4);
    CHECK_NOTHROW(fielddoctor->treat(Paris));
    CHECK((*b)[Paris] == 3);    
    _init();
}

TEST_CASE("treat throw")
{
    init();
    CHECK_THROWS(operationsexpert->treat(Algiers));
    CHECK((*b)[Algiers] == 0);
    CHECK_THROWS(medic->treat(Algiers));
    CHECK((*b)[Algiers] == 0);
    virologist->take_card(Miami);
    virologist->fly_direct(Miami);
    (*b)[Paris] = 5;
    CHECK_THROWS(virologist->treat(Paris));
    CHECK((*b)[Paris] == 5);
    (*b)[London] = 5;
    CHECK_THROWS(fielddoctor->treat(London));
    CHECK((*b)[London] == 5);    
    _init();
}

TEST_CASE("role test")
{
    init();
    CHECK(researcher->role() == "researcher");
    CHECK(scientist->role() == "scientist");
    CHECK(operationsexpert->role() == "operationsexpert");
    CHECK(virologist->role() == "virologist");
    CHECK(medic->role() == "medic");
    CHECK(fielddoctor->role() == "fielddoctor");
    CHECK(dispatcher->role() == "dispatcher");
    CHECK(genesplicer->role() == "genesplicer");
    _init();
}

TEST_CASE("medic abilities")
{
    init();
    (*b)[Algiers] = 5;
    CHECK_NOTHROW(medic->treat(Algiers));
    CHECK((*b)[Algiers] ==0);
    genesplicer->take_card(NewYork);
    genesplicer->take_card(SanFrancisco);
    genesplicer->take_card(Beijing);
    genesplicer->take_card(Karachi);
    genesplicer->take_card(Paris);
    operationsexpert->build();
    genesplicer->discover_cure(Black);
    medic->drive(Paris);
    (*b)[Algiers] = 5;
    medic->drive(Algiers);
    CHECK((*b)[Algiers] == 0);
    (*b)[Cairo] = 5;
    medic->drive(Cairo);
    CHECK((*b)[Cairo] == 0);
    _init();
}

