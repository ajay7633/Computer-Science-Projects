# Project3
#Flight Database - Uses Classes
#Flight Collection

Using a Class, multiple source files, and File Write

This assignment will have all the requirements from Project 2, But implemented my solution using a C++ class. The class created is split into a header file and an implementation file. So, 3 files for this project: one for the main function, one for the header file, and one for the implementation. Also, the user enters a new flight into the database in memory, and will be written in to the flight data file when the program terminates. So, the input file will also be used as an output file: read from it at the beginning of the program and written to it using a member function at program termination. An additional member function called writeFlights() code is written.

The operation and output of the program will be the same as for project 2. Same menu driven options. The search, list, add, and now write functions will become part of the class, so they will be member functions for this project. 

The example file format will be the same as project 1 and project 2:
United Airlines,123,2,28,23.50,3,1,5.75, Portland, Chicago
Jet Blue,345,6,10,8.0,6,10,14.25, Orlando, New York
Southwest,4287,10,10,12.50,10,10,21.25, Atlanta, Seattle
Singapore Airlines,5291,4,5,18.00,4,6,2.50, Las Angeles, Taipei Taiwan
…

Sources:
http://www.cplusplus.com/doc/tutorial/classes/
//https://www.geeksforgeeks.org/c-classes-and-objects/
//https://www.codesdope.com/cpp-file-io/
