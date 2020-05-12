//Name:Ajay M Nair
//Project 5 
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
    //SET FUNCTIONS
    void setAirline(char tairline[]);
    void setDepartAirport(char tdepartAirport[]);
    void setArrivalAirport(char tarriveAirport[]);
    void setFlightNum(int tflightNum);
    void setDepartMonth(int tdepartMon);
    void setDepartDay(int tdepartDay);
    void setDepartTime(double tdepartTime);
    void setArrivalMonth(int tarriveMon);
    void setArrivalDay(int tarriveDay);
    void setArrivalTime(double tarriveTime);
    FlightInfo & operator = (FlightInfo &otherFlight);
    ~FlightInfo();
};


struct node
{
    FlightInfo flight;
    node *link;
};
class FlightCollection {

    node *head;
    node * tail;
    int countNode;
    char fileName[STR_SIZE];

    public:
    ifstream inFile;
    ofstream outFile;
    FlightCollection();
    void writeFlight();
    void addAflight();
    void listItems();
    int loadFlights();
    int getMaxDay(int);
    bool removeFlight();
    void readFile();
    void searchFlight();
    char searchName[STR_SIZE];
    int searchNum;
    ~FlightCollection();

};

#endif
