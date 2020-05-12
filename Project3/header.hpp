//Name:Ajay M Nair
//Project 3
#ifndef __HEADER__
#define __HEADER__
#include <iostream>
#include <fstream>                      //Header Files
#include <iomanip> 
#include <cstring>
using namespace std;

# define STR_SIZE 100                   //Global Constants
# define LIST_SIZE 100
struct flightInfo                       //Struct declaration for each flight
{
    char airline[STR_SIZE];
    int flightNum;
    int departMonth;
    int departDay;
    double departTime;
    int arriveMonth;
    int arriveDay;
    double arriveTime;
    char departAirport[STR_SIZE];
    char arriveAirport[STR_SIZE];
};
class flightCollection {
    flightInfo flights[LIST_SIZE];
    int countAndIndex;
    char fileName[STR_SIZE];

    public:
    ifstream inFile;
    ofstream outFile;
    flightCollection();
    void writeFlight();
    void addAflight();
    void listItems();
    void loadFlights();
    int getMaxDay(int);
    void readFile();
    void searchFlight();
    char searchName[STR_SIZE];
    int searchNum;
    int getIndex();
};
#endif
