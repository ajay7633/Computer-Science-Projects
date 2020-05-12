//Name: Ajay Nair
//Code: Flight Data
//Sources:https://www.hackerearth.com/practice/notes/validating
          //www.cplusplus.com/reference/ios/ios/clear/
          //stackoverflow.com/questions/36229110/c-month-day-and-year-validation

#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;
#define SIZE 100
int day_of_month(int month)
{
if(month==2)
{
    return 28;
}
else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
    return 31;
}
else{
    return 30;
}
}
int error_check2(int mon1,int day1,double time1,int mon2,int day2,double time2){
if(mon1==mon2){
    if(day2>=day1 && day2<= day_of_month(day1))
        {
             if(time2>time1){
                 return 1;
                }
                else{
                cout<<"Arrival time should be greater than Departure time"<<endl;
                return 0;
                 }
        }
        else{
        cout<<"Arrival day should be greater than Departure day and less than "<<day_of_month(day1)<<endl;
        return 0;
        }
    }
else if (mon2>mon1){
    return 1;
}
else{
    cout<<"Error, you must enter a valid month,day,time"<<endl;
    return 0;
}
}
int error_check(int mon,int day,double time){
    int day_check;

    if((mon >=1) & (mon<=12) && ((time >=0) & (time<= 24))){
        day_check=day_of_month(mon);
        if(day>day_check || day ==0){
            cout<<"There are only "<<day_check<<"days in the month"<<endl;
            return 0;
        }
        else {
            return 1;
        }
    }
    else{
        cout<<"Error ,Month should be in the limits of(1-12) and time (0-24)"<<endl;
        return 0;
    }
}
int main(){
int count=0;
char choice=' ';
char name[SIZE];
char departure[SIZE];
char arrival[SIZE];
int flightNum;
int mon_depart,mon_arrival;
int day_depart,day_arrival;
double time_depart;
double time_arrival;
cout<<"Welcome to the flight Data Program."<<endl;
ofstream outFile;
cout<<"What file name would you like to use for your collection? ";
cin.getline(name,SIZE);
outFile.open(name);
while(choice!='N'){
    int m=0,n=0;
        cout<<"\nWhat is the name of the airline? ";
        cin.getline(name,SIZE);
        cout<<"What is flight number? ";
        cin>>flightNum;
        do{
            cout<<"Enter the month,day and time of the Departure: ";
            cin>>mon_depart>>day_depart>>time_depart;
            if(!cin){
                    cout<<"Error, you must enter a valid number for month,day and time"<<endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
            }
            else{
                m=error_check(mon_depart,day_depart,time_depart);
            }
        }while(!m);

         do{
            cout<<"Enter the month,day and time of the Arrival: ";
            cin>>mon_arrival>>day_arrival>>time_arrival;
            if(!cin){
                    cout<<"Error, you must enter a valid number for month,day and time"<<endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
            }
            else{
                m=error_check(mon_arrival,day_arrival,time_arrival);
                n=error_check2(mon_depart,day_depart,time_depart,mon_arrival,day_arrival,time_arrival);
            }
        }while(!(m&n));
        cin.ignore(1000,'\n');
        cout<<"What is the departure city? ";
        cin.getline(departure,SIZE);
        cout<<"What is the arrival city? ";
        cin.getline(arrival,SIZE);
        cout<<"Would you like to enter another flight (y/n)? ";
        cin>>choice;
        ++count;
        choice=toupper(choice);
        while(!(choice=='N' || choice =='Y')){
            cout<<"Please enter a valid key command"<<endl;
            cin>>choice;
            choice=toupper(choice);
        }
        outFile<<fixed<<setprecision(2)<<name<<","<<flightNum<<","<<mon_depart<<","<<day_depart<<","<<time_depart<<","<<mon_arrival<<","<<day_arrival<<","<<time_arrival<<","<<departure<<","<<arrival<<endl;
        cin.ignore();
}
cout<<"You entered "<<count<<" flights"<<endl;
cout<<"End Of Program"<<endl;
outFile.close();
return 0;
}











