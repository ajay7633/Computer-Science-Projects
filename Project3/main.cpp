//Name:Ajay M Nair
//Souces:http://www.cplusplus.com/doc/tutorial/classes/
//      :https://www.geeksforgeeks.org/c-classes-and-objects/
//      :example: ClassFiles: boats.zip ,composition.zip,rectAndBox
//      :https://www.codesdope.com/cpp-file-io/
#include "header.hpp"
int main()
{
    flightCollection temp;//delcaring object
    temp.readFile();
    temp.loadFlights();
    //Function call
    char choice=' ';
    while (choice != 'q')
    {
        cout << "What would you like to do: (a)dd, (l)ist,(s)earch, (q)uit: ";
        cin >> choice;
        switch (choice) {
            case 'a':
                temp.addAflight();
                break;
            case 'l':
                temp.listItems();
                break;
            case 's':
                temp.searchFlight();
                break;
            default:
                cout << "Terminating Program" << endl;
                break;
        }
        temp.writeFlight();
    }
    return 0;
}
