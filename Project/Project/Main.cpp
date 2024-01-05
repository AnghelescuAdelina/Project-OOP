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

void processFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string recordType;
        ss >> recordType;

        if (recordType == "Ticket") {
            // Process Ticket record
            string category;
            ss >> category;
            Ticket ticket(category);
            ticket.displayTicketInfo();
        }
        else if (recordType == "Event") {
            // Process Event record
            string eventName, eventDate, eventTime;
            ss >> eventName >> eventDate >> eventTime;
            Event event(eventName, eventDate, eventTime);
            // Display or store event information as needed
            event.displayEventInfo();
        }
        else if (recordType == "EventTicket") {
            // Process EventTicket record
            string category, eventName;
            ss >> category >> eventName;
            Ticket ticket(category);
            Event event(eventName, "unknown", "unknown");
            EventTicket eventTicket = EventTicket(category, event);
            eventTicket.displayEventTicketInfo();
        }
        else {
            cerr << "Invalid record type: " << recordType << endl;
        }
    }

    inputFile.close();
}

int main() {
    
    }

    // Display an error message if the entered ticket ID is not valid
    if (!validTicket) {
        cerr << "Invalid ticket ID.\n";
    }

    return 0;
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

//Function to find an event by name
Event* findEventByName(const vector<Event>& events, const string& name) {
    auto iterator = find_if(events.begin(), events.end(), [name](const Event& event) {
        return event.getName() == name;
        });

    return (iterator != events.end()) ? &(*iterator) : nullptr;
}