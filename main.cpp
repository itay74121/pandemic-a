#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
#include <random>
#include <time.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;


string help_message = "Welcom to Pandemic game console, in here you can type the following commands \n\
and run a simulation of the game. The commands are:\n\
1. start <playertype> - used to start the game with a certain  player.\n\
2. end - ending the game and printing to the screen if the player won.\n\
3. gps - tell the player the city they are in.\n\
4. takecard <cityname> - take a card for the player.\n\
5. drive <cityname> - drive the player to a near by city.\n\
6. flydirect <cityname> - fly the player to a city by throwing card of that city.\n\
7. flycharter <cityname> - fly the player to a city by throwing the card of the city they are in.\n\
8. flyshuttle <cityname> - fly the player from a city research facility to another city with research facility.\n\
9. build - building a research facility in the city where the player is in.\n\
10. discovercure <color> - discover cure of certain color.\n\
11. treat - treating a city will take one disease points away from it.\n\
12. role - print what role does that player have.\n\
13. status - print the board and more information.\n\
14. infect <cityname> <number>- to infect a city with <number> more desiease point.\n\
Have fun!!!\n";
Board *b = nullptr;
Dispatcher * p1;
FieldDoctor * p2;
GeneSplicer * p3;
Medic * p4;
OperationsExpert * p5;
Researcher * p6;
Scientist *p7;
Virologist * p8;

int main()
{
    int moves = 0;
    int takecards = 0;
    string role;
    b = new Board();
    cout << help_message << endl;
    bool running = true;
    string command;
    string first;
    string second;
    srand(time(0));
    while (running)
    {
        cout << "> "; 
        getline(cin,command,'\n');
        if (command == "")
            continue;
        stringstream stream;
        stream.str(command);
        stream >> first;
        if(first == "start")
        {
            if (!stream.eof())
            {
                stream >> second;
                City c = (City)(rand()%48);
                if(second == "Dispatcher")
                {p1 = new Dispatcher(*b,c);}
                else if(second == "FieldDoctor")
                {p2 = new FieldDoctor(*b,c);}
                else if(second == "GeneSplicer")
                {p3 = new GeneSplicer(*b,c);}
                else if(second == "Medic")
                {p4 = new Medic(*b,c);}
                else if(second == "OperationsExpert")
                {p5 = new OperationsExpert(*b,c);}
                else if(second == "Researcher")
                {p6 = new Researcher(*b,c);}
                else if(second == "Scientist")
                {p7 = new Scientist(*b,c);}
                else if(second == "Virologist")
                {p8 = new Virologist(*b,c);}
                else
                {
                    cout << "role doesn't exists\n";
                    continue;
                }
                role = second;
            }
            else{
                cout << "You must enter a role after start." << endl;
            }
            continue;
        }
        else if(first == "end")
        {
            delete b;
            if(role == "Dispatcher")
            {delete p1; }
            if(role == "FieldDoctor")
            {delete p2;}
            if(role == "GeneSplicer")
            {delete p3;}
            if(role == "Medic")
            {delete p4;}
            if(role == "OperationsExpert")
            {delete p5;}
            if(role == "Researcher")
            {delete p6;}
            if(role == "Scientist")
            {delete p7;}
            if(role == "Virologist")
            {delete p8;}           
            running = false;
            continue;
        }
        else if(first == "gps")
        {
            if(role == "Dispatcher")
            {cout << "Player is at " << pandemic::City_::citytos(p1->getcity())<< endl;}
            else if(role == "FieldDoctor")
            {cout << "Player is at " << pandemic::City_::citytos(p2->getcity())<< endl;}
            else if(role == "GeneSplicer")
            {cout << "Player is at " << pandemic::City_::citytos(p3->getcity())<< endl;}
            else if(role == "Medic")
            {cout << "Player is at " << pandemic::City_::citytos(p4->getcity())<< endl;}
            else if(role == "OperationsExpert")
            {cout << "Player is at " << pandemic::City_::citytos(p5->getcity())<< endl;}
            else if(role == "Researcher")
            {cout << "Player is at " << pandemic::City_::citytos(p6->getcity())<< endl;}
            else if(role == "Scientist")
            {cout << "Player is at " << pandemic::City_::citytos(p7->getcity())<< endl;}
            else if(role == "Virologist")
            {cout << "Player is at " << pandemic::City_::citytos(p8->getcity()) << endl;}     
            else
            {
                cout << "role doesn't exists\n";
            }
            continue;
        }
        else if(first == "takecard")
        {
            stream >> second;
            City c = pandemic::City_::stocity(second);
            if (c == City::NoCity)
            {
                cout << "City doesn't exists\n";
                continue;
            }
            else if(role == "Dispatcher")
            {p1->take_card(c);}
            else if(role == "FieldDoctor")
            {p2->take_card(c);}
            else if(role == "GeneSplicer")
            {p3 ->take_card(c);}
            else if(role == "Medic")
            {p4 ->take_card(c);}
            else if(role == "OperationsExpert")
            {p5 ->take_card(c);}
            else if(role == "Researcher")
            {p6->take_card(c);}
            else if(role == "Scientist")
            {p7->take_card(c);}
            else if(role == "Virologist")
            {p8->take_card(c);}
            else
            {
                cout << "role doesn't exists\n";
                continue;
            }
            moves++;
            takecards++;
            continue;
        }
        else if (first == "drive")
        {
            stream >> second;
            City c = pandemic::City_::stocity(second);
            try{
            if (c == City::NoCity)
            {
                cout << "City doesn't exists\n";
                continue;
            }
            else if(role == "Dispatcher")
            {p1->drive(c);}
            else if(role == "FieldDoctor")
            {p2->drive(c);}
            else if(role == "GeneSplicer")
            {p3 ->drive(c);}
            else if(role == "Medic")
            {p4 ->drive(c);}
            else if(role == "OperationsExpert")
            {p5 ->drive(c);}
            else if(role == "Researcher")
            {p6->drive(c);}
            else if(role == "Scientist")
            {p7->drive(c);}
            else if(role == "Virologist")
            {p8->drive(c);}
            else
            {
                cout << "role doesn't exists\n";
                continue;
            }
            }catch (const logic_error&)
            {
                cout << "Cant drive to "<< second << endl; 
                continue;
            }
            moves++;
            continue;
        }
        else if (first == "flydirect")
        {
            stream >> second;
            City c = pandemic::City_::stocity(second);
            try{
            if (c == City::NoCity)
            {
                cout << "City doesn't exists\n";
                continue;
            }
            else if(role == "Dispatcher")
            {p1->fly_direct(c);}
            else if(role == "FieldDoctor")
            {p2->fly_direct(c);}
            else if(role == "GeneSplicer")
            {p3 ->fly_direct(c);}
            else if(role == "Medic")
            {p4 ->fly_direct(c);}
            else if(role == "OperationsExpert")
            {p5 ->fly_direct(c);}
            else if(role == "Researcher")
            {p6->fly_direct(c);}
            else if(role == "Scientist")
            {p7->fly_direct(c);}
            else if(role == "Virologist")
            {p8->fly_direct(c);}
            else
            {
                cout << "role doesn't exists\n";
                continue;
            }
            }catch (const logic_error&)
            {
                cout << "Cant fly direct to "<< second << endl;
                continue; 
            }
            moves++;
            continue;
        }
        else if (first == "flycharter")
        {
            stream >> second;
            City c = pandemic::City_::stocity(second);
            try{
            if (c == City::NoCity)
            {
                cout << "City doesn't exists\n";
                continue;
            }
            else if(role == "Dispatcher")
            {p1->fly_charter(c);}
            else if(role == "FieldDoctor")
            {p2->fly_charter(c);}
            else if(role == "GeneSplicer")
            {p3 ->fly_charter(c);}
            else if(role == "Medic")
            {p4 ->fly_charter(c);}
            else if(role == "OperationsExpert")
            {p5 ->fly_charter(c);}
            else if(role == "Researcher")
            {p6->fly_charter(c);}
            else if(role == "Scientist")
            {p7->fly_charter(c);}
            else if(role == "Virologist")
            {p8->fly_charter(c);}
            else
            {
                cout << "role doesn't exists\n";
                continue;
            }
            }catch (const logic_error&)
            {
                cout << "Cant fly charter to "<< second << endl; 
                continue;
            }
            moves++;
            continue;
        }
        else if (first == "flyshuttle")
        {
            stream >> second;
            City c = pandemic::City_::stocity(second);
            try{
            if (c == City::NoCity)
            {
                cout << "City doesn't exists\n";
                continue;
            }
            else if(role == "Dispatcher")
            {p1->fly_shuttle(c);}
            else if(role == "FieldDoctor")
            {p2->fly_shuttle(c);}
            else if(role == "GeneSplicer")
            {p3 ->fly_shuttle(c);}
            else if(role == "Medic")
            {p4 ->fly_shuttle(c);}
            else if(role == "OperationsExpert")
            {p5 ->fly_shuttle(c);}
            else if(role == "Researcher")
            {p6->fly_shuttle(c);}
            else if(role == "Scientist")
            {p7->fly_shuttle(c);}
            else if(role == "Virologist")
            {p8->fly_shuttle(c);}
            else
            {
                cout << "role doesn't exists\n";
                continue;
            }
            }catch (const logic_error&)
            {
                cout << "Cant fly shuttle to "<< second << endl; 
                continue;
            }
            moves++;
            continue;
        }
        else if (first == "build")
        {
            try{
            if(role == "Dispatcher")
            {p1->build();}
            else if(role == "FieldDoctor")
            {p2->build();}
            else if(role == "GeneSplicer")
            {p3 ->build();}
            else if(role == "Medic")
            {p4 ->build();}
            else if(role == "OperationsExpert")
            {p5 ->build();}
            else if(role == "Researcher")
            {p6->build();}
            else if(role == "Scientist")
            {p7->build();}
            else if(role == "Virologist")
            {p8->build();}
            else
            {
                cout << "role doesn't exists\n";
                continue;
            }
            }catch (const logic_error&)
            {
                cout << "Cant build in this city" << endl;
                continue;
            }
            continue;
        }
        else if (first == "discovercure")
        {
            stream >> second;
            Color c = pandemic::City_::stocolor(second);
            try{
            if (c == Color::NoColor)
            {
                cout << "Color doesn't exists\n";
                continue;
            }
            else if(role == "Dispatcher")
            {p1->discover_cure(c);}
            else if(role == "FieldDoctor")
            {p2->discover_cure(c);}
            else if(role == "GeneSplicer")
            {p3 ->discover_cure(c);}
            else if(role == "Medic")
            {p4 ->discover_cure(c);}
            else if(role == "OperationsExpert")
            {p5 ->discover_cure(c);}
            else if(role == "Researcher")
            {p6->discover_cure(c);}
            else if(role == "Scientist")
            {p7->discover_cure(c);}
            else if(role == "Virologist")
            {p8->discover_cure(c);}
            else
            {
                cout << "role doesn't exists\n";
                continue;
            }
            }catch (const logic_error&)
            {
                cout << "Cant discover cure of color "<< second << endl; 
                continue;
            }
            moves++;
            continue;
        } 
        else if (first == "treat")
        {
            stream >> second;
            City c = pandemic::City_::stocity(second);
            try{
            if (c == City::NoCity)
            {
                cout << "City doesn't exists\n";
                continue;
            }
            else if(role == "Dispatcher")
            {p1->treat(c);}
            else if(role == "FieldDoctor")
            {p2->treat(c);}
            else if(role == "GeneSplicer")
            {p3 ->treat(c);}
            else if(role == "Medic")
            {p4 ->treat(c);}
            else if(role == "OperationsExpert")
            {p5 ->treat(c);}
            else if(role == "Researcher")
            {p6->treat(c);}
            else if(role == "Scientist")
            {p7->treat(c);}
            else if(role == "Virologist")
            {p8->treat(c);}
            else
            {
                cout << "role doesn't exists\n";
                continue;
            }
            }catch (const logic_error&)
            {
                cout << "Cant treat the city "<< second << endl; 
                continue;
            }
            moves++;
            continue;
        }
        else if (first == "role")
        {
            if(role == "Dispatcher")
            {cout << "The role is " << p1->role() <<endl;}
            else if(role == "FieldDoctor")
            {cout << "The role is " << p2->role()<<endl;}
            else if(role == "GeneSplicer")
            {cout << "The role is " << p3 ->role()<<endl;}
            else if(role == "Medic")
            {cout << "The role is " << p4 ->role()<<endl;}
            else if(role == "OperationsExpert")
            {cout << "The role is " << p5 ->role()<<endl;}
            else if(role == "Researcher")
            {cout << "The role is " << p6->role()<<endl;}
            else if(role == "Scientist")
            {cout << "The role is " << p7->role()<<endl;}
            else if(role == "Virologist")
            {cout << "The role is " << p8->role()<<endl;}
            else
            {
                cout << "role doesn't exists\n";
            }
            continue;
        }
        else if(first == "status")
        {
            if (b != nullptr)
            {
                cout << *b << endl;
                cout << "Player role is " << role << endl;
                cout << "Number of turns is " << moves << endl;
                cout << "Player took "<<takecards<<" cards" <<endl;

            }
            else
            {
                cout << "You didn't start the game yet."<<endl;
            }
        }
        else if(first == "infect")
        {
            if (!stream.eof())
            {
                stream >> second;
                string number;
                if(!stream.eof())
                {
                    stream >> number;
                }
                else
                {
                    cout << "Missing third parameter\n";
                    continue;
                }
                City c = pandemic::City_::stocity(second);
                if (c == City::NoCity)
                {
                    cout << "City doesn't exists\n";
                }
                int num = stoi(number);
                (*b)[c] += num;
            }
            else
            {
                cout << "Missing second parameter\n";
            }
            continue;
        }
        else{
            cout << "Command you typed isn't listed\n";
        }
    }
    return 0;
}








