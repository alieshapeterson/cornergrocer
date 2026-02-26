#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "GroceryItem.h"
const std::string CYAN = "\033[36m";  // cyan text
const std::string RESET = "\033[0m";  // Reset text color back to default
using namespace std;

// Constants

// Menu choices
const int SEARCH_ITEM = 1;
const int DISPLAY_ALL = 2;
const int DISPLAY_HISTOGRAM = 3;
const int EXIT_PROGRAM = 4; 

// Functions

// Read input file and build a vector of GroceryItem objects
vector<GroceryItem> loadGroceryData(const string& fileName);

// Write the grocery list to a backup file
void createBackupFile(const vector<GroceryItem>& groceryList);

// Display menu options to the user
void displayMenu();

// Convert a string to lowercase (for case-insensitive search)
string toLower(const string& str);

// Function Definitions

// Convert string to lowercase
string toLower(const string& str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Read input file and create grocery item list
vector<GroceryItem> loadGroceryData(const string& fileName)
{
    vector<GroceryItem> groceryList;  // Stores all items from file
    ifstream inputFile(fileName);
    string itemName;

    if (!inputFile.is_open())
    {
        cout << "Error opening file: " << fileName << endl;
        return groceryList; // Return empty list if file fails
    }

    while (getline(inputFile, itemName))
    {
        if (itemName.empty())
        {
            continue;  // Skip blank lines
        }

        bool itemExists = false;

        // Check if the item is already in the list
        for (size_t index = 0; index < groceryList.size(); ++index)
        {
            if (groceryList[index].getName() == itemName)
            {
                groceryList[index].incrementQuantity(); // Increase count if found
                itemExists = true;
                break;
            }
        }

        // Add new item if not already in the list
        if (!itemExists)
        {
            groceryList.push_back(GroceryItem(itemName, 1));
        }
    }

    inputFile.close();
    return groceryList;
}

// Create a backup file frequency.dat
void createBackupFile(const vector<GroceryItem>& groceryList)
{
    ofstream outputFile("frequency.dat");

    if (!outputFile.is_open())
    {
        cout << "Error creating backup file." << endl;
        return;
    }

    // Write each item and its quantity to the backup file
    for (size_t index = 0; index < groceryList.size(); ++index)
    {
        outputFile << groceryList[index].getName() << " "
            << groceryList[index].getQuantity() << endl;
    }

    outputFile.close();
}

// Display menu options
void displayMenu()
{
    cout << "\n===== Grocery Menu =====" << endl;
    cout << "1. Search for item frequency" << endl;
    cout << "2. Display all frequencies" << endl;
    cout << "3. Display histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter choice: ";
}

// MAIN PROGRAM

int main()
{
    const string fileName = "CS210_Project_Three_Input_File.txt";
    int userChoice = 0;

    // Create backup at program start 
    vector<GroceryItem> initialList = loadGroceryData(fileName); // Load current file data
    createBackupFile(initialList);                                 // Save to frequency.dat
    cout << "Initial backup file created (frequency.dat)." << endl;

    // Start menu loop 
    while (userChoice != EXIT_PROGRAM)
    {
        displayMenu();

        // Validate user input
        while (!(cin >> userChoice) || userChoice < SEARCH_ITEM || userChoice > EXIT_PROGRAM)
        {
            cout << "Invalid input. Enter 1-4: ";
            cin.clear();               // Clear input error flag
            cin.ignore(1000, '\n');    // Remove invalid input from buffer
        }

        if (userChoice == EXIT_PROGRAM)
        {
            break; // Exit menu loop
        }

        // Load current data from input file 
        vector<GroceryItem> groceryList = loadGroceryData(fileName);

        if (userChoice == SEARCH_ITEM)
        {
            string searchItem;
            cout << "Enter item to search: ";
            cin >> searchItem;

            int frequency = 0;
            string searchLower = toLower(searchItem);

            // Search for item in the list
            for (size_t index = 0; index < groceryList.size(); ++index)
            {
                if (toLower(groceryList[index].getName()) == searchLower)
                {
                    frequency = groceryList[index].getQuantity();
                    break;
                }
            }

            cout << searchItem << " appears " << frequency << " time(s)." << endl;
        }
        else if (userChoice == DISPLAY_ALL)
        {
            // Display all items and their quantities
            for (size_t index = 0; index < groceryList.size(); ++index)
            {
                cout << setw(15) << left
                    << groceryList[index].getName()
                    << groceryList[index].getQuantity() << endl;
            }
        }
        else if (userChoice == DISPLAY_HISTOGRAM)
        {
            // Display histogram of items
            for (size_t index = 0; index < groceryList.size(); ++index)
            {
                cout << setw(15) << left
                    << groceryList[index].getName();

                // Print stars equal to item quantity in cyan
                for (int star = 0; star < groceryList[index].getQuantity(); ++star)
                {
                    cout << CYAN << "*" << RESET;  // Apply cyan color, then reset
                }

                cout << endl;
            }
        }
    }

    cout << "Exiting program." << endl;
    return 0;
}