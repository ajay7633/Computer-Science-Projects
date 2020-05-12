//Name:Ajay M Nair
//Project 4 
#ifndef __HEADER__
#define __HEADER__
#include <iostream>
#include <fstream>                      //Header Files
#include <iomanip> 
#include <cstring>
using namespace std;

# define STR_SIZE 100                   //Global Constants
# define LIST_SIZE 100
class FlightInfo                      //class declaration for each flight
{
    char * airline;
    int flightNum;
    int departMonth;
    int departDay;
    double departTime;
    int arriveMonth;
    int arriveDay;
    double arriveTime;
    char * departAirport;
    char * arriveAirport;
    public:
    FlightInfo();
    // default contructor
    //constructor with arguments
    FlightInfo(char[], int, int, int, double, int, int, double, char[], char[]);
    const char * getAirline();
    const char* getDepartAirport();
    const char* getArrivalAirport();
    int getFlightNum();
    int getDepartMonth();
    int getDepartDay();
    double getDepartTime();
    int getArrivalMonth();
    int getArrivalDay();
    double getArrivalTime();
    ~FlightInfo();//destructor
};

class FlightCollection {
    FlightInfo * flights[LIST_SIZE];
    int countAndIndex;
    char fileName[STR_SIZE];

    public:
    ifstream inFile;
    ofstream outFile;
    FlightCollection();
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
    ~FlightCollection();
};
#endif
