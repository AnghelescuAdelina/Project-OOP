#include "Ticket.h"
#include "EventLocation.h"
#include "Event.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Generate and display multiple tickets for different categories
    cout << "Generating and displaying tickets:\n";
    vector<string> ticketCategories = { "VIP", "Regular", "Student" };
    vector<Ticket> tickets;

    for (const string& category : ticketCategories) {
        tickets.emplace_back(category);
        tickets.back().displayTicketInfo();
        cout << "\n";
    }

    // Interact with the user to input information for events and tickets
    string eventName, eventDate, eventTime;
    cout << "Enter event details:\n";

    // Clear input buffer before taking user input
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Event Name: ";
    getline(cin, eventName);

    cout << "Event Date: ";
    getline(cin, eventDate);

    cout << "Event Time: ";
    getline(cin, eventTime);

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

    for (const Ticket& ticket : tickets) {
        if (ticket.getUniqueID() == ticketID) {
            cout << "Ticket is valid.\n";
            validTicket = true;
            break;
        }
    }

    if (!validTicket) {
        cerr << "Invalid ticket ID.\n";
    }

    return 0;
}
