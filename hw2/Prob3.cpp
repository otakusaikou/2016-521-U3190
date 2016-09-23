#include <iostream>
#include <fstream>
#include <string>
#include "Sales_item.h"

using namespace std;

// Function for reading text file
ifstream &openFile(ifstream &fin, const string &fileName)
{
    fin.close();                    // Close in case it was already open
    fin.clear();                    // Clear any existing errors
    fin.open(fileName.c_str());     // Open the file with given file name
    return fin;
}

int main()
{
    // Initialize variables
    string fileName;
    ifstream fin;
    Sales_item curItem;
    Sales_item nextItem;

    // User input
    cout << "Enter the file name: ";
    cin >> fileName;

    // Open text file
    if (!openFile(fin, fileName)) {
        cerr << "Complain: I cannot find the file" << endl << endl;
        return -1;
    }

    // Deal with the sales item input file
    fin >> curItem;                     // Read the first sales item
    while (fin >> nextItem) {
        // Check if current and next sales items have the same isbn
        if (curItem.isbn() == nextItem.isbn()) {
            curItem += nextItem;        // Update the current sales item
        } else {
            cout << curItem << endl;
            curItem = nextItem;         // Change to next item
        }
    }
    cout << curItem << endl;            // Output the last sales item
    return 0;
}
