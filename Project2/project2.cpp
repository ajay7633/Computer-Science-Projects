//Name:Ajay M Nair
//Project 2
//Sources:https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-points-with-cout
//          https://stackoverflow.com/questions/22490559/char-pointers-invalid-conversion-from-char-to-char 
//          https://stackoverflow.com/questions/19978672/compare-const-char-with-strcmp
//          Project1Design.cpp(InclassFiles)
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
struct type{
    flightInfo list[LIST_SIZE];
    int count=0;
};
//Function Prototypes
void addAflight(struct type &temp);
void listItems(struct type & temp);
void loadFlights(ifstream &inFile, struct type &airlines);
int getMaxDay(int theMonth);
void searchFlight(struct type &temp,char searchName[],int searchNum);
//Main Start
int main()
{
    ifstream inFile;
    type airlines;
    char searchName[STR_SIZE];
    int searchNum;
    char filename[STR_SIZE];
    cout<<"Welcome to the flight information program. what is the name of the flight data file?: ";
    cin.getline(filename,STR_SIZE);
    inFile.open(filename);                                  //File Retrieve
    while (!inFile) {
        cout << "Error Unable to open file..Please enter the correct filename: " ;
        cin.getline(filename,STR_SIZE);
        inFile.open(filename);
    }
    loadFlights(inFile, airlines);                          //Function call
    char choice=' ';
    while(choice != 'q'){
        cout<<"What would you like to do: (a)dd, (l)ist,(s)earch, (q)uit: ";
        cin>>choice;
        switch(choice){
            case 'a':
                addAflight(airlines);
                break;
            case 'l':
                listItems(airlines);
                break;
            case 's':
                cout<<"For what flights would you like to search: ";
                cin.ignore(STR_SIZE,'\n');
                cin.getline(searchName,STR_SIZE);
                cout<<"What is the search Number: ";
                cin>>searchNum;
                searchFlight(airlines,searchName,searchNum);
                cin.ignore();
                break;
            default:
                cout<<"Terminating Program"<<endl;
                break;
        }
    }
    return 0;
}
//All the Functions are defined below
//Load Flight function : Loads the flights from file in directory
void loadFlights(ifstream &inFile,struct type &airlines) {
    char flightNumStr[STR_SIZE];
    char departMonthStr[STR_SIZE];
    char departDayStr[STR_SIZE];
    char departTimeStr[STR_SIZE];
    char arriveMonthStr[STR_SIZE];
    char arriveDayStr[STR_SIZE];
    char arriveTimeStr[STR_SIZE];
    int count = 0;
    while (!inFile.eof()) {//end of file
        inFile.getline(airlines.list[count].airline, STR_SIZE, ',');
        inFile.getline(flightNumStr, STR_SIZE, ',');
        airlines.list[count].flightNum = atoi(flightNumStr);
        inFile.getline(departMonthStr, STR_SIZE, ',');
        airlines.list[count].departMonth = atoi(departMonthStr);
        inFile.getline(departDayStr, STR_SIZE, ',');
        airlines.list[count].departDay = atoi(departDayStr);
        inFile.getline(departTimeStr, STR_SIZE, ',');
        airlines.list[count].departTime = atof(departTimeStr);
        inFile.getline(arriveMonthStr, STR_SIZE, ',');
        airlines.list[count].arriveMonth = atoi(arriveMonthStr);
        inFile.getline(arriveDayStr, STR_SIZE, ',');
        airlines.list[count].arriveDay = atoi(arriveDayStr);
        inFile.getline(arriveTimeStr, STR_SIZE, ',');
        airlines.list[count].arriveTime = atof(arriveTimeStr);
        inFile.getline(airlines.list[count].departAirport, STR_SIZE, ',');
        inFile.getline(airlines.list[count].arriveAirport, STR_SIZE, '\n');
        count++;
    }
    count--;
    airlines.count=count; 
    cout << "Sucessfully loaded " << count << "flights" << endl;
    listItems(airlines); 
}
// This Function returns the days present in each of months in a year
//Used for error check in addAflight()
int getMaxDay(int theMonth){
    int maxDay;
    switch(theMonth){
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
//Adds a flight to the database.
//All error checks are done in this function.
void addAflight(struct type &temp){
    int i = temp.count;
    int max;
    if(i<LIST_SIZE){
        cout<<"what is name of airline :";
        cin.ignore();
        cin.getline(temp.list[i].airline,STR_SIZE);
        cout<<"What is flight number: ";
        cin>>temp.list[i].flightNum;
        while(cin.fail() || temp.list[i].flightNum<=0)
        {
            cin.clear();
            cin.ignore(STR_SIZE,'\n');
            cout<<"Please enter a positive number: ";
            cin>>temp.list[i].flightNum;
        }
        cout<<"What is the departure month? :";
        cin>>temp.list[i].departMonth;
        while(cin.fail() || temp.list[i].departMonth<1 || temp.list[i].departMonth>12)
        {
            cin.clear();
            cin.ignore(STR_SIZE,'\n');
            cout<<"Please enter a valid month (1-12): ";
            cin>>temp.list[i].departMonth;
        }
        max=getMaxDay(temp.list[i].departMonth);
        cout<<"What is the departure day? :";
        cin>>temp.list[i].departDay;
        while(temp.list[i].departDay<1 || temp.list[i].departDay > max)
        {
            cin.clear();
            cin.ignore(STR_SIZE,'\n');
            cout<<"Please enter a valid departure day: ";
            cin>>temp.list[i].departDay;
        }
        cout<<"What is the departTime? :";
        cin>>temp.list[i].departTime;
        while(cin.fail() || temp.list[i].departTime<0 || temp.list[i].departTime > 23.59)
        {
            cin.clear();
            cin.ignore(STR_SIZE,'\n');
            cout<<"Please enter a valid departure Time 0-24: ";
            cin>>temp.list[i].departTime;
        }

        cout<<"What is the arrival month? :";
        cin>>temp.list[i].arriveMonth;
        while(cin.fail() || temp.list[i].arriveMonth < temp.list[i].departMonth || temp.list[i].departMonth>12)
        {
            cin.clear();
            cin.ignore(STR_SIZE,'\n');
            cout<<"Arrival month cannont  be before the departure month. Please re-enter Arrival month: ";
            cin>>temp.list[i].arriveMonth;
        }
        cout<<"What is the arrival day? :";
        max=getMaxDay(temp.list[i].arriveMonth);
        cin>>temp.list[i].arriveDay;
        if(temp.list[i].arriveMonth==temp.list[i].departMonth){
            while(temp.list[i].arriveDay < temp.list[i].departDay || temp.list[i].arriveDay > max)
            {
                cin.clear();
                cin.ignore(STR_SIZE,'\n');
                cout<<"Arrival day is not within the limits: "<<temp.list[i].departDay<<" and "<<max;
                cin>>temp.list[i].arriveDay;
            }
        }
        else{
            while(temp.list[i].arriveDay < 1 || temp.list[i].arriveDay > max)
            {
                cin.clear();
                cin.ignore(STR_SIZE,'\n');
                cout<<"Please Enter a valid arrival day: ";
                cin>>temp.list[i].arriveDay;
            }
        }
        cout<<"What is the arrival Time? :";
        cin>>temp.list[i].arriveTime;
        if(temp.list[i].arriveMonth==temp.list[i].departMonth && temp.list[i].arriveDay == temp.list[i].departDay){
            while(cin.fail() || temp.list[i].arriveTime <= temp.list[i].departTime || temp.list[i].arriveTime > 23.59)
            {
                cin.clear();
                cin.ignore(STR_SIZE,'\n');
                cout<<"Please enter a valid Arrival Time 0-24: ";
                cin>>temp.list[i].arriveTime;
            }
        }
        cout<<"What is the departure airport? " ;
        cin.ignore();
        cin.getline(temp.list[i].departAirport,STR_SIZE);
        cout<<"What is the arrival airport? ";
        cin.getline(temp.list[i].arriveAirport,STR_SIZE);
        temp.count++;
        cout<<temp.list[i].airline<<" "<<temp.list[i].flightNum<<" was sucessfully added to the flight DataBase"<<endl;
    }
    else{
        cout<<" Sorry there is no more room for items"<<endl;
    }
}
//All the flights will be listed
//Those added to the database aswell as the the flights loaded from file
void listItems(struct type & temp){
    cout<<"Airline"<<"\t\t\t"<<"Flight#"<<"\t\t"<<"Departure"<<"\t\t"<<"Arrival"<<"\t\t\t"<<"From"<<"\t\t"<<"To"<<endl;
    cout<<"======================================================================================================================"<<endl;
    for(int i=0;i<temp.count;i++){
        cout<<fixed<<setprecision(2)
            <<left<<setw(25)<<temp.list[i].airline
            <<left<<setw(15)<<temp.list[i].flightNum
            <<temp.list[i].departMonth<<"/"
            <<temp.list[i].departDay
            <<" at "
            <<setw(15)<<temp.list[i].departTime
            <<temp.list[i].arriveMonth<<"/"
            <<temp.list[i].arriveDay<<" at "
            <<setw(15)<<temp.list[i].arriveTime
            <<setw(20)<<temp.list[i].departAirport
            <<setw(20)<<temp.list[i].arriveAirport<<endl;
    }
}
//Searches for a particular Flight and Gives all the rewuired details about the flight
void searchFlight(struct type &temp,char searchName[],int searchNum)
{
    int count=0;
    int found=0;
    for(count;count<temp.count;count++)
    {
        if((strcmp(searchName,temp.list[count].airline)==0) && temp.list[count].flightNum==searchNum)
        {
            found++;
            cout<<"Information on "<<searchName<<" "<<searchNum<<" is as follows: "<<endl;
            cout<<"Departure Date and Time: "<<temp.list[count].departMonth<<"/"<<temp.list[count].departDay<<" at "<<temp.list[count].departTime<<" From: "
                <<temp.list[count].departAirport<<" To: "<<temp.list[count].arriveAirport<<endl;

        }
    }
    if(found==0)
    {
        cout<<searchName<<" "<<searchNum<<" was not found in the database"<<endl;
    }
}

