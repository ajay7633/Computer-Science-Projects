//Name:Ajay M Nair
#include "header.hpp"
//Default Constructor for FlightInfo Class
FlightInfo::FlightInfo(){
    airline = nullptr;
    departAirport = nullptr;
    arriveAirport = nullptr;

}

//Destructor for FlightInfo class
FlightInfo::~FlightInfo() {
    if(airline != nullptr){
        delete[]airline;
        airline = nullptr;
    }
    if(departAirport != nullptr){
        delete[]departAirport;
        departAirport = nullptr;
    }
    if(arriveAirport != nullptr){
        delete[] arriveAirport;
        arriveAirport = nullptr;
    }
} 

//
// Getter function
//
const char* FlightInfo::getAirline() {
    return airline;
}
const char* FlightInfo::getDepartAirport()
{
    return departAirport;
}
const char* FlightInfo::getArrivalAirport()
{
    return arriveAirport;
}
int FlightInfo::getFlightNum() {
    return flightNum;
}
int FlightInfo::getDepartMonth() {
    return departMonth;
}
int FlightInfo::getDepartDay() {
    return departDay;
}
double FlightInfo::getDepartTime()
{
    return departTime;
}
int FlightInfo::getArrivalMonth() {
    return arriveMonth;
}
int FlightInfo::getArrivalDay() {
    return arriveDay;
}
double FlightInfo::getArrivalTime()
{
    return arriveTime;
}
//Flight Info Contructor which takes arguments
FlightInfo::FlightInfo(char tairline[],int tflightNum, int tdepartMon,int tdepartDay,double tdepartTime,int tarriveMon,int tarriveDay,double tarriveTime,char tdepartAirport[],char tarriveAirport[])
{
    int len;
    len = strlen(tairline);
    airline = new char[len + 1];
    strcpy(airline, tairline);
    flightNum = tflightNum;
    departMonth = tdepartMon;
    departDay = tdepartDay;
    departTime = tdepartTime;
    arriveMonth = tarriveMon;
    arriveDay = tarriveDay;
    arriveTime = tarriveTime;
    len = strlen(tdepartAirport);
    departAirport = new char[len + 1];
    strcpy(departAirport, tdepartAirport);
    len = strlen(tarriveAirport);
    arriveAirport = new char[len + 1];
    strcpy(arriveAirport, tarriveAirport);
}
//Default Constructor for Flight Collection
FlightCollection::FlightCollection() {
    countAndIndex = 0;
    for(int i=0 ;i < LIST_SIZE ; i++){
        flights[i]=nullptr;
    }
}
//Return the Current Index
int FlightCollection::getIndex() {
    int index;
    index = countAndIndex;
    return index;
}
//
//This function returns the maximum days in the corresponding month
//
int FlightCollection::getMaxDay(int theMonth)
{
    switch (theMonth) 
    {
        case 2:
            return 28;
            break;
        case 4: //foll through
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        default:
            ;
    }
}
//
//Read Flight function : Opens the file in directory
//
void FlightCollection::readFile() 
{
    char quit[] = "quit";
    cout << "Welcome to the flight information program. what is the name of the flight data file? or type 'quit' to exit: ";
    cin.getline(fileName, STR_SIZE);
    if (strcmp(fileName, quit) == 0)
    {
        cout << "You decided to Terminate the Program , Press any key to continue " << endl;
        cin.get();
        exit(0);
    }
    inFile.open(fileName);  
    //File Retrieve
    while (!inFile) {
        cout << "Error Unable to open file..Please enter the correct filename: ";
        cin.getline(fileName, STR_SIZE);
        inFile.open(fileName);
        if (strcmp(fileName, quit) == 0)
        {
            cout << "You decided to Terminate the Program , Press any key to continue " << endl;
            cin.get();
            exit(0);
        }
    }
}
//
//Load Flight Function : Loads Flights from the File
//
void FlightCollection::loadFlights() {
    char tairline[STR_SIZE];
    int tflightNum;
    int tdepartMon;
    int tdepartDay;
    double tdepartTime;
    int tarriveMon;
    int tarriveDay;
    double tarriveTime;
    char flightNumStr[STR_SIZE];
    char departMonthStr[STR_SIZE];
    char departDayStr[STR_SIZE];
    char departTimeStr[STR_SIZE];
    char arriveMonthStr[STR_SIZE];
    char arriveDayStr[STR_SIZE];
    char arriveTimeStr[STR_SIZE];
    char tdepartAirport[STR_SIZE];
    char tarriveAirport[STR_SIZE];
    int count = 0;
    if (count < LIST_SIZE) {
        while (!inFile.eof()) {//end of file

            inFile.getline(tairline, STR_SIZE, ',');
            inFile.getline(flightNumStr, STR_SIZE, ',');
            tflightNum = atoi(flightNumStr);
            inFile.getline(departMonthStr, STR_SIZE, ',');
            tdepartMon= atoi(departMonthStr);
            inFile.getline(departDayStr, STR_SIZE, ',');
            tdepartDay = atoi(departDayStr);
            inFile.getline(departTimeStr, STR_SIZE, ',');
            tdepartTime = atof(departTimeStr);
            inFile.getline(arriveMonthStr, STR_SIZE, ',');
            tarriveMon = atoi(arriveMonthStr);
            inFile.getline(arriveDayStr, STR_SIZE, ',');
            tarriveDay = atoi(arriveDayStr);
            inFile.getline(arriveTimeStr, STR_SIZE, ',');
            tarriveTime = atof(arriveTimeStr);
            inFile.getline(tdepartAirport, STR_SIZE, ',');
            inFile.getline(tarriveAirport, STR_SIZE, '\n');
            flights[count]= new FlightInfo(tairline, tflightNum, tdepartMon, tdepartDay, tdepartTime, tarriveMon, tarriveDay, tarriveTime, tdepartAirport, tarriveAirport);
            count++;
            inFile.peek(); // check for the end of file marker.
        }
        countAndIndex = count;
        cout << "Sucessfully loaded " << count << " flights" << endl;
        listItems();

        inFile.close(); //just added
    }
    else {
        cout << " Sorry there is no more room for items" << endl;
    }
}
//
// Add a Flight Function : Allows User to add flights 
//
void FlightCollection::addAflight() {
    int i = countAndIndex;
    int max;
    char tAirline[STR_SIZE];
    int tflightNum;
    int tdepartMonth;
    int tdepartDay;
    double tdepartTime;
    int tarriveMonth;
    int tarriveDay;
    double tarriveTime;
    char tdepartAirport[STR_SIZE];
    char tarriveAirport[STR_SIZE];
    if (i<LIST_SIZE) {

        cout << "what is name of airline :";
        cin.ignore();
        cin.getline(tAirline, STR_SIZE);
        cout << "What is flight number: ";
        cin >> tflightNum;
        while (cin.fail() || tflightNum <= 0)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a positive number: ";
            cin >> tflightNum;
        }
        cout << "What is the departure month? :";
        cin >> tdepartMonth;
        while (cin.fail() || tdepartMonth<1 || tdepartMonth>12)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a valid month (1-12): ";
            cin >> tdepartMonth;
        }
        max = getMaxDay(tdepartMonth);
        cout << "What is the departure day? :";
        cin >> tdepartDay;
        while (tdepartDay<1 || tdepartDay > max)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a valid departure day: ";
            cin >> tdepartDay;
        }
        cout << "What is the departTime? :";
        cin >> tdepartTime;
        while (cin.fail() || tdepartTime < 0 || tdepartTime > 23.59)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a valid departure Time 0-24: ";
            cin >> tdepartTime;
        }

        cout << "What is the arrival month? :";
        cin >> tarriveMonth;
        while (cin.fail() || tarriveMonth < tdepartMonth || tdepartMonth>12)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Arrival month cannont  be before the departure month. Please re-enter Arrival month: ";
            cin >> tarriveMonth;
        }
        cout << "What is the arrival day? :";
        max = getMaxDay(tarriveMonth);
        cin >> tarriveDay;
        if (tarriveMonth == tdepartMonth) {
            while (tarriveDay < tdepartDay || tarriveDay > max)
            {
                cin.clear();
                cin.ignore(STR_SIZE, '\n');
                cout << "Arrival day is not within the limits: " << tdepartDay << " and " << max;
                cin >> tarriveDay;
            }
        }
        else {
            while (tarriveDay < 1 || tarriveDay > max)
            {
                cin.clear();
                cin.ignore(STR_SIZE, '\n');
                cout << "Please Enter a valid arrival day: ";
                cin >> tarriveDay;
            }
        }
        cout << "What is the arrival Time? :";
        cin >> tarriveTime;
        ////
        ////just added
        ////
        while (tarriveTime > 23.59) {
            cout << "Please enter a valid Arrival Time 0-24: ";
            cin >> tarriveTime;
        }
        ////
        ////
        if (tarriveMonth == tdepartMonth && tarriveDay == tdepartDay) {
            while (cin.fail() || tarriveTime <= tdepartTime || tarriveTime > 23.59)
            {
                cin.clear();
                cin.ignore(STR_SIZE, '\n');
                cout << "Please enter a valid Arrival Time 0-24: ";
                cin >> tarriveTime;
            }
        }
        cout << "What is the departure airport? ";
        cin.ignore();
        cin.getline(tdepartAirport, STR_SIZE);
        cout << "What is the arrival airport? ";
        cin.getline(tarriveAirport, STR_SIZE);
        flights[countAndIndex] = new FlightInfo(tAirline, tflightNum, tdepartMonth, tdepartDay, tdepartTime, tarriveMonth, tarriveDay, tarriveTime, tdepartAirport, tarriveAirport);
        countAndIndex++;
        cout << tAirline << " " << tflightNum << " was sucessfully added to the flight DataBase" << endl;

    }
    else {
        cout << " Sorry there is no more room for items" << endl;
    }
}
//
//List the flights : All the flights will be listed
//Those added to the database aswell as the the flights loaded from file
//
void FlightCollection::listItems() {
    cout << "Airline" << "\t\t\t" << "Flight#" << "\t\t" << "Departure" << "\t\t" << "Arrival" << "\t\t\t" << "From" << "\t\t" << "To" << endl;
    cout << "======================================================================================================================" << endl;
    int m = countAndIndex;
    for (int i = 0; i<m; i++) {
        cout << fixed << setprecision(2)
            << left << setw(25) << flights[i]->getAirline()
            << left << setw(15) << flights[i]->getFlightNum()
            << flights[i]->getDepartMonth()<< "/"
            << flights[i]->getDepartDay()
            << " at "
            << setw(15) << flights[i]->getDepartTime()
            << flights[i]->getArrivalMonth()<< "/"
            << flights[i]->getArrivalDay() << " at "
            << setw(15) << flights[i]->getArrivalTime()
            << setw(20) << flights[i]->getDepartAirport()
            << setw(20) << flights[i]->getArrivalAirport() << endl;
    }
}
//
//Search Flight Function : Allows the User to Search Flights :Outputs all Info on flights if found
//
void FlightCollection::searchFlight()
{
    cout << "For what flights would you like to search: ";
    cin.ignore(STR_SIZE, '\n');
    cin.getline(searchName, STR_SIZE);
    cout << "What is the search Number: ";
    cin >> searchNum;
    while (!cin)
    {
        cin.clear();
        cout << "please re-enter a number : ";
        cin.ignore(STR_SIZE, '\n');
        cin >> searchNum;
    }
    cin.ignore();
    int count = 0;
    int found = 0;
    for (count; count < countAndIndex; count++)
    {
        if ((strcmp(searchName, flights[count]->getAirline()) == 0) && flights[count]->getFlightNum() == searchNum)
        {
            found++;
            cout << "Information on " << searchName << " " << searchNum << " is as follows: " << endl;
            cout << "Departure Date and Time: " << flights[count]->getDepartMonth() << "/" << flights[count]->getDepartDay() << " at " << flights[count]->getDepartTime() << " From: "
                << flights[count]->getDepartAirport() << " To: " << flights[count]->getArrivalAirport() << endl;

        }
    }
    if (found == 0)
    {
        cout << searchName << " " << searchNum << " was not found in the database" << endl;
    }
}
//
//Write File Function : Ability to write the function to the file
//
void FlightCollection::writeFlight() {
    outFile.open(fileName);
    int m = countAndIndex;
    for (int i = 0; i < m; i++) {

        outFile << flights[i]->getAirline() << "," << flights[i]->getFlightNum() << "," << flights[i]->getDepartMonth() << "," << flights[i]->getDepartDay() << ","
            << flights[i]->getDepartTime() << "," << flights[i]->getArrivalMonth()<<"," << flights[i]->getArrivalDay()<<"," << flights[i]->getArrivalTime()<<","
            << flights[i]->getDepartAirport()<<"," << flights[i]->getArrivalAirport()<<endl;
    }
    outFile.close();
}
//Destructor for FlightCollection class
FlightCollection::~FlightCollection(){
    for(int i=0; i < countAndIndex ; i++)
    {
        if(flights[i] != nullptr){
            delete flights[i];
            flights[i] =nullptr;
        }

    }
}

//
//END OF PROGRAM
