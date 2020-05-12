# Project2
Flight Information - Using struct modification from Project 1

Project 2
Flight Information Program

Please refer to Project 1 If you haven’t already, as it is a progressive development. For this Project, I have written C++ program that keeps track of a set of flights. Instead of saving flight information to a file like project 1, this time flight information loaded into memory, so the flights can be listed and searched. When the program starts, your program will ask the user to enter the name of an input file, which your program will open and use to load the flight information into memory using an array of structs. The input text file will use the same comma separated value format as project 1. After the file is loaded, the program will enter a user-controlled loop. Inside of the loop, the program will ask the user what they want to do. In addition to searching and listing, the user will have the option to add another flight to the database, but only in memory; new flight information is not added to the text file for this project. So, the options that the user can select are:
•	Search for a flight by name and number.
•	List all the flights.
•	Add a new flight to the memory database.
•	Quit.

There are 4 functions that are written for this project in addition to main: loadFlights(), addAFlight(), searchFlights(), and listFlights(). 

Remember from project 1 that the file format contains all the information for one flight on one line.

Example Program Execution Output (User Input in Bold):

Welcome to the flight information program. What is the name of the flight data file? notAFile.txt
notAFile.txt was not found. Try again or type 'quit' to exit the program.
What is the name of the flight data file? flights.txt
Successfully loaded 2 flights.

Airline      Flight#     Departure        Arrival          From         To
-------------------------------------------------------------------------------
United       123         2/28 at 23.50    3/1 at 5.75      Portland     Chicago
Jet Blue     345         6/10 at 8.00     6/10 at 14.25    Orlando      New York


What would you like to do? (S)earch for a flight, (A)dd a flight, (L)ist all flights, or (Q)uit? A
What is the name of the airline? Southwest
What is the flight number? 4287 
Enter the month, day and time of the departure: October 10 12.5
Error, you must enter a number for the month day and time.
Enter the month, day and time of the departure: 10 10 12.5
Enter the month, day and time of the arrival:   7 11 9.25
Error, the arrival day and time must be after the departure day and time.
Enter the month, day and time of the arrival:   10 10 21.25
What is the departure city? Atlanta
What is the arrival city? Seattle
Southwest 4287 was successfully added to the database.

What would you like to do? (S)earch for a flight, (A)dd a flight, (L)ist all flights, or (Q)uit? S
For what flight would you like to search? Alaska 375
Alaska 375 was not found in the database.

What would you like to do? (S)earch for a flight, (A)dd a flight, (L)ist all flights, or (Q)uit? S
For what flight would you like to search? Southwest 4287
Information on Southwest 4287 is as follows:
Departure Date and Time: 10/10 at 12.5, Arrival Date and Time: 10/10 at 21.25, From: Atlanta To: Seattle

What would you like to do? (S)earch for a flight, (A)dd a flight, (L)ist all flights, or (Q)uit? L

Airline      Flight#     Departure        Arrival          From         To
-------------------------------------------------------------------------------
United       123         2/28 at 23.50    3/1 at 5.75      Portland     Chicago
Jet Blue     345         6/10 at 8.00     6/10 at 14.25    Orlando      New York
Southwest    4287        10/10 at 12.5    10/10 at 21.25   Atlanta      Seattle

What would you like to do? (S)earch for a flight, (A)dd a flight, (L)ist all flights, or (Q)uit? Q
Terminating Program.

Programming Requirements
•	Not used string library or any of the STL containers such as vectors. Used the <cstring> library and c-strings (char arrays) to store strings. 
•	Created array of structs in the main function. Not used any global variables (constant globals are OK).
•	Checked for input failure and negative values 

Sources
//Sources: https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-points-with-cout
//https://stackoverflow.com/questions/22490559/char-pointers-invalid-conversion-from-char-to-char 
//https://stackoverflow.com/questions/19978672/compare-const-char-with-strcmp
