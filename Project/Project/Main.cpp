// Main.cpp
#include "Ticket.h"
#include "EventLocation.h"
#include "Event.h"

#include <iostream>
#include <string>

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
