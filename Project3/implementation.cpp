//Name:Ajay M Nair
#include "header.hpp"
//Default Constructor
flightCollection::flightCollection() 
{
    countAndIndex = 0;
}
//Return the Current Index
int flightCollection::getIndex() {
    int index;
    index = countAndIndex;
    return index;
}
//
//This function returns the maximum days in the corresponding month
//
int flightCollection::getMaxDay(int theMonth)
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
void flightCollection::readFile() 
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
void flightCollection::loadFlights() {
    char flightNumStr[STR_SIZE];
    char departMonthStr[STR_SIZE];
    char departDayStr[STR_SIZE];
    char departTimeStr[STR_SIZE];
    char arriveMonthStr[STR_SIZE];
    char arriveDayStr[STR_SIZE];
    char arriveTimeStr[STR_SIZE];
    int count = 0;
    if (count < LIST_SIZE) {
        while (!inFile.eof()) {//end of file
            inFile.getline(flights[count].airline, STR_SIZE, ',');
            inFile.getline(flightNumStr, STR_SIZE, ',');
            flights[count].flightNum = atoi(flightNumStr);
            inFile.getline(departMonthStr, STR_SIZE, ',');
            flights[count].departMonth = atoi(departMonthStr);
            inFile.getline(departDayStr, STR_SIZE, ',');
            flights[count].departDay = atoi(departDayStr);
            inFile.getline(departTimeStr, STR_SIZE, ',');
            flights[count].departTime = atof(departTimeStr);
            inFile.getline(arriveMonthStr, STR_SIZE, ',');
            flights[count].arriveMonth = atoi(arriveMonthStr);
            inFile.getline(arriveDayStr, STR_SIZE, ',');
            flights[count].arriveDay = atoi(arriveDayStr);
            inFile.getline(arriveTimeStr, STR_SIZE, ',');
            flights[count].arriveTime = atof(arriveTimeStr);
            inFile.getline(flights[count].departAirport, STR_SIZE, ',');
            inFile.getline(flights[count].arriveAirport, STR_SIZE, '\n');
            count++;
        }
        count--;
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
void flightCollection::addAflight() {
    int i = countAndIndex;
    int max;
    if (i<LIST_SIZE) {
        cout << "what is name of airline :";
        cin.ignore();
        cin.getline(flights[i].airline, STR_SIZE);
        cout << "What is flight number: ";
        cin >> flights[i].flightNum;
        while (cin.fail() || flights[i].flightNum <= 0)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a positive number: ";
            cin >> flights[i].flightNum;
        }
        cout << "What is the departure month? :";
        cin >> flights[i].departMonth;
        while (cin.fail() || flights[i].departMonth < 1 || flights[i].departMonth > 12)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a valid month (1-12): ";
            cin >> flights[i].departMonth;
        }
        max = getMaxDay(flights[i].departMonth);
        cout << "What is the departure day? :";
        cin >> flights[i].departDay;
        while (flights[i].departDay < 1 || flights[i].departDay > max)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a valid departure day: ";
            cin >> flights[i].departDay;
        }
        cout << "What is the departTime? :";
        cin >> flights[i].departTime;
        while (cin.fail() || flights[i].departTime<0 || flights[i].departTime > 23.59)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Please enter a valid departure Time 0-24: ";
            cin >> flights[i].departTime;
        }

        cout << "What is the arrival month? :";
        cin >> flights[i].arriveMonth;
        while (cin.fail() || flights[i].arriveMonth < flights[i].departMonth || flights[i].departMonth>12)
        {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Arrival month cannont  be before the departure month. Please re-enter Arrival month: ";
            cin >> flights[i].arriveMonth;
        }
        cout << "What is the arrival day? :";
        max = getMaxDay(flights[i].arriveMonth);
        cin >> flights[i].arriveDay;
        if (flights[i].arriveMonth == flights[i].departMonth) {
            while (flights[i].arriveDay < flights[i].departDay || flights[i].arriveDay > max)
            {
                cin.clear();
                cin.ignore(STR_SIZE, '\n');
                cout << "Arrival day is not within the limits: " << flights[i].departDay << " and " << max;
                cin >> flights[i].arriveDay;
            }
        }
        else {
            while (flights[i].arriveDay < 1 || flights[i].arriveDay > max)
            {
                cin.clear();
                cin.ignore(STR_SIZE, '\n');
                cout << "Please Enter a valid arrival day: ";
                cin >> flights[i].arriveDay;
            }
        }
        cout << "What is the arrival Time? :";
        cin >> flights[i].arriveTime;
        while (flights[i].arriveTime > 23.59) {
            cout << "Please enter a valid Arrival Time 0-24: ";
            cin >> flights[i].arriveTime;
        }
        if (flights[i].arriveMonth == flights[i].departMonth && flights[i].arriveDay == flights[i].departDay) {
            while (cin.fail() || flights[i].arriveTime <= flights[i].departTime || flights[i].arriveTime > 23.59)
            {
                cin.clear();
                cin.ignore(STR_SIZE, '\n');
                cout << "Arrival time cannot be before or same time as Departure time ";
                cin >> flights[i].arriveTime;
            }
        }
        cout << "What is the departure airport? ";
        cin.ignore();
        cin.getline(flights[i].departAirport, STR_SIZE);
        cout << "What is the arrival airport? ";
        cin.getline(flights[i].arriveAirport, STR_SIZE);
        countAndIndex++;
        cout << flights[i].airline << " " << flights[i].flightNum << " was sucessfully added to the flight DataBase" << endl;
    }
    else {
        cout << " Sorry there is no more room for items" << endl;
    }
}
//
//List the flights : All the flights will be listed
//Those added to the database aswell as the the flights loaded from file
//
void flightCollection::listItems() {
    cout << "Airline" << "\t\t\t" << "Flight#" << "\t\t" << "Departure" << "\t\t" << "Arrival" << "\t\t\t" << "From" << "\t\t" << "To" << endl;
    cout << "======================================================================================================================" << endl;
    int m = countAndIndex;
    for (int i = 0; i < m; i++) {
        cout << fixed << setprecision(2)
            << left << setw(25) << flights[i].airline
            << left << setw(15) << flights[i].flightNum
            << flights[i].departMonth << "/"
            << flights[i].departDay
            << " at "
            << setw(15) << flights[i].departTime
            << flights[i].arriveMonth << "/"
            << flights[i].arriveDay << " at "
            << setw(15) << flights[i].arriveTime
            << setw(20) << flights[i].departAirport
            << setw(20) << flights[i].arriveAirport << endl;
    }
}
//
//Search Flight Function : Allows the User to Search Flights :Outputs all Info on flights if found
//
void flightCollection::searchFlight()
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
    //searchFlight(airlines, searchName, searchNum);
    cin.ignore();
    int found = 0;
    for (int count=0 ; count < countAndIndex; count++)
    {
        if ((strcmp(searchName, flights[count].airline) == 0) && flights[count].flightNum == searchNum)
        {
            found++;
            cout << "Information on " << searchName << " " << searchNum << " is as follows: " << endl;
            cout << "Departure Date and Time: " << flights[count].departMonth << "/" << flights[count].departDay << " at " << flights[count].departTime << " From: "
                << flights[count].departAirport << " To: " << flights[count].arriveAirport << endl;

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
void flightCollection::writeFlight() {
    outFile.open(fileName);
    int m = countAndIndex;
    for (int i = 0; i < m; i++) {

        outFile << flights[i].airline << "," << flights[i].flightNum << "," << flights[i].departMonth << "," << flights[i].departDay<<","
            << flights[i].departTime << "," << flights[i].arriveMonth << "," << flights[i].arriveDay << "," << flights[i].arriveTime << ","
            << flights[i].departAirport << "," << flights[i].arriveAirport<<endl;
    }
    outFile.close();
}
//
//END OF PROGRAM
