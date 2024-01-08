// Main.cpp
#include "Ticket.h"
#include "EventLocation.h"
#include "EventTicket.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//Function to process data from a file

void processFromFile(const string& filename, vector<Event>& events, EventLocation& eventLocation) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Read eventLocation information from the file
    inputFile >> eventLocation;

    // Read events from the file
    while (!inputFile.eof()) {
        Event event;
        inputFile >> event;
        events.push_back(event);
    }

    inputFile.close();
}


int main(int argumentcounter, char* argumentvector[]) {
    if (argumentcounter > 1) {
        //Comand-line mode: process data from the specified file
        processFromFile(argumentvector[1]);
    }
    else {
        //Interactive mode:display menu for user interaction
        int choice;
        Ticket ticket;
        EventLocation eventLocation;
        EventTicket eventTicket;

        do {
            cout << "Menu:\n";
            cout << "1.";
            cout<<"2."
        }
    }
}

//Function implementations

// Function to display the main menu
void displayMenu(vector<Event>& events) {
    int choice;

    do {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Create Ticket\n";
        cout << "2. Read Event from File\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (events.empty()) {
                cerr << "No events available. \n";
            }
            else {
                createTicket(events[0]); 
            }
            break;

        case 2:
            readEventFromFile(events);
            break;

        case 3:
            cout << "Exiting the program.\n";
            break;

        default:
            cerr << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

