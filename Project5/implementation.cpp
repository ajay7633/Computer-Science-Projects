//Name:Ajay M Nair
#include "header.hpp"

//Default Constructor for Flight Collection
FlightCollection::FlightCollection() {
    countNode= 0;
    head = nullptr;
}

//Default Constructor for FlightInfo Class

FlightInfo::FlightInfo(){
    airline = nullptr;
    departAirport = nullptr;
    arriveAirport = nullptr;

}
//Destructot for Flight coolection
FlightCollection::~FlightCollection(){
    node* cur= head;
    while(cur!=nullptr)
    {
        cur = head->link;
        delete head;
        head=cur;

    }
}
//Destructor for FlightInfo class
FlightInfo::~FlightInfo()
{
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
// Getter function: Returns values stored in private variables in Flightinfo
//
const char* FlightInfo::getAirline()
{
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
int FlightInfo::getDepartDay()
{
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
//
//Setter Functions: Sets values to the private members in flightInfo
//
void FlightInfo::setArrivalMonth(int tarriveMon)
{
    arriveMonth = tarriveMon;
}
void FlightInfo::setArrivalDay(int tarriveDay)
{
    arriveDay = tarriveDay;
}
void FlightInfo::setArrivalTime(double tarriveTime)
{
    arriveTime = tarriveTime;
}
void FlightInfo::setDepartMonth(int tdepartMon) {
    departMonth = tdepartMon;
}
void FlightInfo::setDepartDay(int tdepartDay)
{
    departDay = tdepartDay;
}
void FlightInfo::setDepartTime(double tdepartTime)
{
    departTime = tdepartTime;
}

void FlightInfo::setAirline(char tairline[]) {
    airline = new char[strlen(tairline) + 1];
    strcpy(airline, tairline);
}
void FlightInfo::setDepartAirport(char tdepartAirport[]) {

    departAirport = new char[strlen(tdepartAirport) + 1];
    strcpy(departAirport, tdepartAirport);
}
void FlightInfo::setArrivalAirport(char tarriveAirport[]) {

    arriveAirport = new char[strlen(tarriveAirport) + 1];
    strcpy(arriveAirport, tarriveAirport);
}
void FlightInfo::setFlightNum(int tflightNum) {
    flightNum = tflightNum;
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
int FlightCollection::loadFlights() {
    FlightInfo tempFlight;
    node *temp;
    node *prev, *cur;

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
    //
    //node *next,*cur;
    if (count < LIST_SIZE) {

        while (!inFile.eof()) {//end of file
            temp = new node;
            temp->link = NULL;
            inFile.getline(tairline, STR_SIZE, ',');
            inFile.getline(flightNumStr, STR_SIZE, ',');
            tflightNum = atoi(flightNumStr);
            inFile.getline(departMonthStr, STR_SIZE, ',');
            tdepartMon = atoi(departMonthStr);
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
            //           FlightInfo tempFlight(tairline, tflightNum, tdepartMon, tdepartDay, tdepartTime, tarriveMon, tarriveDay, tarriveTime, tdepartAirport, tarriveAirport);

            temp->flight.setAirline(tairline);
            temp->flight.setFlightNum(tflightNum);
            temp->flight.setDepartMonth(tdepartMon);
            temp->flight.setDepartDay(tdepartDay);
            temp->flight.setDepartTime(tdepartTime);
            temp->flight.setArrivalMonth(tarriveMon);
            temp->flight.setArrivalDay(tarriveDay);
            temp->flight.setArrivalTime(tarriveTime);
            temp->flight.setDepartAirport(tdepartAirport);
            temp->flight.setArrivalAirport(tarriveAirport);
            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else
            {
                if (strcmp(temp->flight.getAirline(), head->flight.getAirline()) < 0) {
                    temp->link = head;
                    head = temp;
                }
                //Implements Sorted Order
                else
                {
                    prev = head;
                    cur = head->link;
                    while (cur != NULL) {
                        if (strcmp(prev->flight.getAirline(), temp->flight.getAirline()) < 0 && strcmp(cur->flight.getAirline(), temp->flight.getAirline()) > 0)
                        {
                            prev->link = temp;
                            temp->link = cur;
                            break;
                        }
                        else
                        {
                            prev = cur;
                            cur = cur->link;
                        }
                    }
                    if (cur == NULL) {
                        prev->link = temp;
                        tail = temp;
                    }
                }
            }
            this->countNode = this->countNode + 1;
            count++;
            inFile.peek();
        }
        cout << "Sucessfully loaded " << count << " flights" << endl;
        //List out the Items
        listItems();
        inFile.close(); //just added
        return this->countNode;
    }
    else {
        cout << " Sorry there is no more room for items" << endl;
    }
}

//
// Add a Flight Function : Allows User to add flights 
//
void FlightCollection::addAflight() {
    node *temp = new node;
    node * prev = head;
    node * cur = head;
    int i = this->countNode;
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

    temp->flight.setArrivalAirport(tarriveAirport);
    if (i < LIST_SIZE) {

        cout << "what is name of airline :";
        cin.ignore();
        cin.getline(tAirline, STR_SIZE);
        temp->flight.setAirline(tAirline);
        cout << "What is flight number: ";
        cin >> tflightNum;
        temp->flight.setFlightNum(tflightNum);
        while (cin.fail() || tflightNum <= 0)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a positive number: ";
            cin >> tflightNum;
            temp->flight.setFlightNum(tflightNum);
        }
        cout << "What is the departure month? :";
        cin >> tdepartMonth;
        temp->flight.setDepartMonth(tdepartMonth);
        while (cin.fail() || tdepartMonth < 1 || tdepartMonth>12)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a valid month (1-12): ";
            cin >> tdepartMonth;
            temp->flight.setDepartMonth(tdepartMonth);
        }
        max = getMaxDay(tdepartMonth);
        cout << "What is the departure day? :";
        cin >> tdepartDay;
        temp->flight.setDepartDay(tdepartDay);
        while (tdepartDay<1 || tdepartDay > max)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a valid departure day: ";
            cin >> tdepartDay;
            temp->flight.setDepartDay(tdepartDay);
        }
        cout << "What is the departTime? :";
        cin >> tdepartTime;
        temp->flight.setDepartTime(tdepartTime);
        while (cin.fail() || tdepartTime<0 || tdepartTime > 23.59)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a valid departure Time 0-24: ";
            cin >> tdepartTime;
            temp->flight.setDepartTime(tdepartTime);
        }

        cout << "What is the arrival month? :";
        cin >> tarriveMonth;
        temp->flight.setArrivalMonth(tarriveMonth);
        while (cin.fail() || tarriveMonth < tdepartMonth || tdepartMonth>12)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Arrival month cannont  be before the departure month. Please re-enter Arrival month: ";
            cin >> tarriveMonth;
            temp->flight.setArrivalMonth(tarriveMonth);
        }
        cout << "What is the arrival day? :";
        max = getMaxDay(tarriveMonth);
        cin >> tarriveDay;
        temp->flight.setArrivalDay(tarriveDay);
        if (tarriveMonth == tdepartMonth)
        {
            while (tarriveDay < tdepartDay || tarriveDay > max)
            {
                cin.clear();
                cin.ignore(STR_SIZE, '\n');
                cout << "Arrival day is not within the limits: " << tdepartDay << " and " << max;
                cin >> tarriveDay;
                temp->flight.setArrivalDay(tarriveDay);
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
        temp->flight.setArrivalTime(tarriveTime);
        ////
        ////just added
        ////
        while (tarriveTime > 23.59) {
            cout << "Please enter a valid Arrival Time 0-24: ";
            cin >> tarriveTime;
            temp->flight.setArrivalTime(tarriveTime);
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
                temp->flight.setArrivalTime(tarriveTime);
            }
        }
        cout << "What is the departure airport? ";
        cin.ignore();
        cin.getline(tdepartAirport, STR_SIZE);
        temp->flight.setDepartAirport(tdepartAirport);
        cout << "What is the arrival airport? ";
        cin.getline(tarriveAirport, STR_SIZE);
        temp->flight.setArrivalAirport(tarriveAirport);

        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else
        {
            if (strcmp(temp->flight.getAirline(), head->flight.getAirline()) < 0) {
                temp->link = head;
                head = temp;
            }
            else
            {
                prev = head;
                cur = head->link;
                while (cur != NULL) {
                    if (strcmp(prev->flight.getAirline(), temp->flight.getAirline()) < 0 && strcmp(cur->flight.getAirline(), temp->flight.getAirline()) > 0)
                    {
                        prev->link = temp;
                        temp->link = cur;
                        break;
                    }
                    else
                    {
                        prev = cur;
                        cur = cur->link;
                    }
                }
                if (cur == NULL) {
                    prev->link = temp;
                    tail = temp;
                }
            }
        }
        this->countNode = this->countNode + 1;
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
    node * temp;
    temp = head;
    cout << "Airline" << "\t\t\t" << "Flight#" << "\t\t" << "Departure" << "\t\t" << "Arrival" << "\t\t\t" << "From" << "\t\t" << "To" << endl;
    cout << "======================================================================================================================" << endl;
    for (int i = 0; i < this->countNode; i++) {
        cout << fixed << setprecision(2)
            << left << setw(25) << temp->flight.getAirline()
            << left << setw(15) << temp->flight.getFlightNum()
            << temp->flight.getDepartMonth() << "/"
            << temp->flight.getDepartDay()
            << " at "
            << setw(15) << temp->flight.getDepartTime()
            << temp->flight.getArrivalMonth() << "/"
            << temp->flight.getArrivalDay() << " at "
            << setw(15) << temp->flight.getArrivalTime()
            << setw(20) << temp->flight.getDepartAirport()
            << setw(20) << temp->flight.getArrivalAirport() << endl;
        temp = temp->link;
    }
}
//
//Search Flight Function : Allows the User to Search Flights :Outputs all Info on flights if found
//
void FlightCollection::searchFlight()
{
    node * temp;
    temp = head;
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
    //searchFlight(airlines, searchName, searchNum);
    cin.ignore(100,'\n');
    //int count = 0;
    int found = 0;

    for (int i = 0; i < this->countNode; i++)
    {
        if ((strcmp(searchName, temp->flight.getAirline()) == 0) && temp->flight.getFlightNum() == searchNum)
        {
            found++;
            cout << "Information on " << searchName << " " << searchNum << " is as follows: " << endl;
            cout << "Departure Date and Time: " << temp->flight.getDepartMonth() << "/" << temp->flight.getDepartDay() << " at " << temp->flight.getDepartTime() << " From: "
                << temp->flight.getDepartAirport() << " To: " << temp->flight.getArrivalAirport() << endl;

        }
        temp = temp->link;
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
    node * temp;
    temp = head;
    for (int i = 0; i < this->countNode; i++) {

        outFile << temp->flight.getAirline() << "," << temp->flight.getFlightNum() << "," << temp->flight.getDepartMonth() << "," << temp->flight.getDepartDay() << ","
            << temp->flight.getDepartTime() << "," << temp->flight.getArrivalMonth()<<"," << temp->flight.getArrivalDay()<<"," << temp->flight.getArrivalTime()<<","
            << temp->flight.getDepartAirport()<<"," << temp->flight.getArrivalAirport()<<endl;
        temp = temp->link;
    }
    outFile.close();
}
//
//Removes a Flight from the list
//
//
bool FlightCollection::removeFlight() {
    node *prev = head;
    node *cur = head;
    bool found = false;
    cout << "Which flight would you like to remove: ";
    cin.ignore(STR_SIZE, '\n');
    cin.getline(searchName, STR_SIZE);
    while (cur != NULL) {  // if cur == null, then end of list.
        if (strcmp(searchName, cur->flight.getAirline()) == 0) { // found the right node.
            found = true;
            break;
        }
        else {
            // Move down the list.
            prev = cur;
            cur = cur->link;
        }
    }

    if (found) {
        if (cur == head) {
            // code to delete the head.
            head = cur->link;
            delete cur;
            cur = head;
        }
        else {
            prev->link = cur->link;
            delete cur;
        }
        cout << "The Flight " << searchName << " is removed sucessfully.\n " << endl;
        this->countNode = this->countNode - 1;
    }
    else {
        cout << "The Flight " << searchName << " was not deleted in the database. Try different Name!\n" << endl;
    }
    return found;
}

//
//END OF PROGRAM
