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

// Function to search for an event by name
bool searchEventByName(const vector<Event>& events, const string& eventName, Event& foundEvent) {
    for (const auto& event : events) {
        if (event.getName() == eventName) {
            foundEvent = event;
            return true;  // Event found
        }
    }
    return false;  // Event not found
}
// Function to display available seats for a specific category
void displayAvailableSeats(const EventLocation& eventLocation, const string& category) {
    cout << "Available seats for category " << category << ":\n";
    for (int row = 1; row <= eventLocation.getNumRows(); ++row) {
        for (int zone = 1; zone <= eventLocation.getNumZones(); ++zone) {
            if (eventLocation.isSeatAvailable(row, zone, category)) {
                cout << "Row: " << row << ", Zone: " << zone << "\n";
            }
        }
    }
}

// Function to sell a ticket
bool sellTicket(EventTicket& eventTicket, const EventLocation& eventLocation, int row, int zone) {
    //Sell the ticket and update availability
    if (eventLocation.isSeatAvailable(row, zone, eventTicket.getCategory())) {
        eventTicket.sellTicket(row, zone);
        return true;
    }
    return false;
}


int main(int argc, char* argv[]) {
    if (argc > 1) {
        // Command-line mode: process data from the specified file
        vector<Event> events;
        EventLocation eventLocation;
        processFromFile(argv[1], events, eventLocation);
    }
    else {
        // Interactive mode: display menu for user interaction
        int choice;
        Ticket ticket;
        EventLocation eventLocation;
        EventTicket eventTicket;
        vector<Event> events;  // Store events from the file

        do {
            cout << "Menu:\n";
            cout << "1. Search and display event by name\n";
            cout << "2. Check ticket availability\n";
            cout << "3. Sell a ticket\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                // Search and display event by name
            {
                string eventName;
                cout << "Enter event name to search: ";
                cin >> eventName;

                Event foundEvent;
                if (searchEventByName(events, eventName, foundEvent)) {
                    // Display event information
                    foundEvent.displayEventInfo();
                }
                else {
                    cout << "Event not found.\n";
                }
            }
            break;

            case 2:
                // Check ticket availability
            {
                // Assume the user has selected an event and knows the category
                string category;;
                cout << "Enter ticket category: ";
                cin >> ws;
                getline(cin, category);

                // Display available seats for the specified category
                displayAvailableSeats(eventLocation, category);
            }
            break;

            case 3:
                // Sell a ticket
            {
                // Assume the user has selected an event and knows the category
                string category;
                cout << "Enter ticket category: ";
                cin >> ws;
                getline(cin, category);

                // Example: Sell a ticket for a specific row and zone
                int row, zone;
                cout << "Enter row and zone: ";
                cin >> row >> zone;

                if (sellTicket(eventTicket, eventLocation, row, zone)) {
                    cout << "Ticket sold successfully!\n";
                }
                else {
                    cout << "Failed to sell ticket.\n";
                }
            }
            break;

            case 4:
                // Exit the program
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            }

        } while (choice != 4);
    }

    return 0;
}

