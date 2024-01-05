// Main.cpp
#include "Ticket.h"
#include "EventLocation.h"
#include "Event.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//Function prototypes
void displayMenu(vector<Event>& events);
void createTicket(Event& event);
void displayTicketInfo(const Ticket& ticket);
void saveData(const vector<Event>& events);
void restoreData(vector<Event>& events);
Event* findEventByName(const vector<Event>& events, const string& name);
void displayEventDetails(const Event& event);
void readEventFromFile(vector<Event>& events);

using namespace std;

int main() {
    // Generate and display multiple tickets for different categories
    cout << "Generating and displaying tickets:\n";

    // Define an array of ticket categories
    string ticketCategories[] = { "VIP", "Regular", "Student" };

    // Create an array of Ticket objects
    Ticket tickets[3];

    // Generate tickets for each category and display ticket information
    for (int i = 0; i < 3; ++i) {
        tickets[i] = Ticket(ticketCategories[i]);
        tickets[i].displayTicketInfo();
        cout << "\n";
    }

    // Interact with the user to input information for events and tickets
    string eventName, eventDate, eventTime;
    cout << "Enter event details:\n";

    // Clear input buffer before taking user input
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get event details from the user
    cout << "Event Name: ";
    getline(cin, eventName);

    cout << "Event Date: ";
    getline(cin, eventDate);

    cout << "Event Time: ";
    getline(cin, eventTime);

    // Create an Event object with user-provided details
    Event event(eventName, eventDate, eventTime);

    // Display event information
    cout << "\nEvent Information:\n";
    event.displayEventInfo();
    cout << "\n";

    // Validate tickets
    int ticketID;
    cout << "Enter a ticket ID for validation: ";
    cin >> ticketID;

    bool validTicket = false;

    // Check if the entered ticket ID matches any of the generated tickets
    for (int i = 0; i < 3; ++i) {
        if (tickets[i].getUniqueID() == ticketID) {
            cout << "Ticket is valid.\n";
            validTicket = true;
            break;
        }
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