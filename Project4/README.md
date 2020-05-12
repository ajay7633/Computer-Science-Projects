# Project4 : Flight Collection
#Flight Database: Using dynamic memory allocation


This assignment will have all the requirements from Project 3, but implemented solution using dynamic memory for flightInfo
and c-string data members. Continued using three files for the project, one for the main function, one for the header file, 
and one for the implementation. 
For project 3, I set up struct to use c-strings that were a constant size, and most of that memory went to waste. 

Consider the memory set up for the name of the airline: char airline[strSize]; and strSize was set to at least 100. 
The name “United Airlines” for example only uses 16 chars (including the null terminator), so 84 bytes are wasted. 
For this project, I set up just the right amount of dynamic memory for each c-string.

[NOTE: The other large waste of memory from assignment 3 is the array of structs in the FlightCollection class. 
There were about 4 flights in the example file, but enough room to accommodate 100, depending on the ARRAY_SIZE constant.
If only 4 flights are in the collection, then 96 structs are allocated but not used.
For this Project, I still used a fixed size array, but the array elements will be pointers,
instead of actual objects. So, I won’t allocate the objects until they are needed,
and if they are never needed, then only 8 bytes (the size of a pointer) will be wasted,
instead of all of the memory for an unused object (at least 300 bytes for each struct if strSize is set to 100: airline,
depart and arrival airports, each 100 chars).]

The input text file format will be the same as it was for project 2 and 3, i.e., a comma separated value file.
The operation and output of this project will be the same as project 3.
Consult the project 2 document for example output.
Look at the struct from project 3 and compare that to the class I used for project 4 .
Notice that FlightInfo has gone from a struct to a class. Also notice that all the c-strings have been replaced with char pointers.
The main differences in the implementation file will be in loadFlights() and addAFlight(), because those are the two methods that
store data in memory. 


