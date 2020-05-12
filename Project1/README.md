# Project1
#Flight Database : Takes User inputs and stores information in file
#Project 1
#Flight Information Database

C++ program that keeps a database of flights. When the program starts, User enters the name of an output file, and then the program will enter a user-controlled loop. Inside of the loop, the program will ask the user to enter several details about a flight. The program will output all information to output file.
Requirements:

•	The airline company, as a c-string.
•	The flight number, as an integer.
•	The month and day of the departure, both stored as integers.
•	The departure time of the flight stored as a double.
•	The month and day of the arrival, both stored as integers.
•	The arrival time of the flight stored as a double.
•	The departure airport stored as a c-string.
•	The arrival airport stored as a c-string.

Information on the Project:

•	The information in the file in the same order:
•	Airline, flight number, departure month, day, time, arrival month, day, time, departure city, arrival city. 
A flight that leaves at 6:30 for example is stored as 6.5. Used 24 hours, so a 2:30 flight for example would be stored as 14.5 (2:30 pm plus 12:00 noon).

Each month stored using an integer. January is 1, February is 2, etc., up to December, which is 12.
Each month has a specific number of days: January, March, May, July, August, October, and December all have 31 days. April, June, September, and November have 30 days. The odd one out is February, which has 28 days (leap years ignored). 

24-hour times fall between 0.0 inclusive to 24.0 exclusive. So, 0.0 is midnight, and 23.99 is 6/10th of a second before midnight.

Data checking to make sure a flight departs on a day and time before the day and time that it arrives. A flight can arrive on or after the same day that it departs, but it must arrive after the departure time. So, if the departure month is 3 (March), then the arrival month must be between 3 and 12 inclusive. 
March has 31 days, so if the arrival month is also 3 and the departure day is the 20th, then the arrival day must be between 20 and 31 inclusive. If the month and day are equal, check was done to ensure times to make sure the arrival is after the departure. 

Impossibly long flights, like 6 months, or impossibly short flights, like 1 second was not considered in this project
After the user types the details about a flight and checked the data for correctness, the data is stored to the output file that the user specified when the program started. In addition, keep a running total of 
After writing the data to the file and your code reaches the bottom of the loop, if you would like to enter another flight. Type ‘y’ or ‘Y’ for yes, reenter the loop to ask for information about the next flight. If they type ‘n’ or ‘N’ for no, then stop the loop. The total number of flights entered will be displayed at program termination.

Example Output
Welcome to the flight data program.
What file name would you like to use for your collection? flights.txt

What is the name of the airline? United Airlines
What is the flight number? 123
Enter the month, day and time of the departure: 2 28 23.5
Enter the month, day and time of the arrival:   3 1 5.75
What is the departure city? Portland
What is the arrival city? Chicago

Would you like to enter another flight (y/n)? y
Welcome to the flight data program.
What is the name of the airline? Jet Blue
What is the flight number? 345 
Enter the month, day and time of the departure: Hi 28 23.5
Error, you must enter a number for the month day and time.
Enter the month, day and time of the departure: 13 28 23.5
Error, you must enter a valid number for the month day and time.
Enter the month, day and time of the departure: 6 10 8.0
Enter the month, day and time of the arrival:   6 8 14.25
Error, the arrival day and time must be after the departure day and time.
Enter the month, day and time of the arrival:   6 10 14.25
What is the departure city? Orlando
What is the arrival city? New York


Would you like to enter another flight (y/n)? n
----------
You entered 2 flights.
End of Program.

Example Output File
United Airlines,123,2,28,23.50,3,1,5.75, Portland, Chicago
Jet Blue,345,6,10,8.0,6,10,14.25, Orlando, New York

Souces:
https://www.hackerearth.com/practice/notes/validating
      //www.cplusplus.com/reference/ios/ios/clear/
      //stackoverflow.com/questions/36229110/c-month-day-and-year-validation
