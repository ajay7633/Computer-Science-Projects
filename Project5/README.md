# Project5
#Flight Database:Using a Linear Linked List

This Project will have all the requirements from Project 4, I implemented solution using a linked list.
Continued to use three files for your project, one for the main function, one for the header file, and
one for the implementation. 

There are three additional functions for project 5:

•	Created a removeFlight() function to allow the user to remove any flight from the database in memory,
based on airline and flightnum.
•	Added the flights to memory in alphabetically sorted order, according to the name of the flight,
in both loadFlights() and in addAFlight().
•	Create an overloaded assignment operator function for the FlightInfo class.

Program Information

•	For Project 4, I used an array of class pointers, but for this version,
I won’t be declaring an array at all. The FlightInfo class is mostly unchanged,
but there is a new struct for this project. In the class definition, I replaced the array of FlightInfo pointers
with a pointer to a node struct called head. 

•	The node struct only has two members: a FlightInfo object and a link pointer. The link pointer is the link to
the next struct in the linked list. See below for more details.

•	Except for the overloaded assignment method, everything else with the FlightInfo class will be the same as it was for project 4.
Namely, dynamically allocated c-strings. Used the same method to allocate memory and strcpy () from a temporary string.

•	Notice in the FlightCollection class that I have changed the name of countAndIndex to just count. This is because I won’t be
needing an index anymore, because we no longer have an array. 

Sources:

#http://www.cplusplus.com/doc/tutorial/classes/
#https://www.geeksforgeeks.org/destructors-c/
#https://www.geeksforgeeks.org/c-classes-and-objects/
#https://www.codesdope.com/cpp-file-io/

