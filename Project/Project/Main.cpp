// Main.cpp
#include "Ticket.h"
#include "EventLocation.h"
#include "Event.h"

using namespace std;

int main() {
    // Create an instance of Ticket
    Ticket ticket("VIP");

    // Display ticket information
    cout << "Ticket Information:\n";
    ticket.displayTicketInfo();
    cout << "\n";

    // Create an instance of EventLocation
    vector<int> seatsPerRow = { 20, 25, 30 };
    EventLocation location(1000, 10, 3, seatsPerRow);

    // Display event location information
    cout << "Event Location Information:\n";
    location.displayLocationInfo();
    cout << "\n";

    // Create an instance of Event
    Event event("Concert", "2023-12-01", "19:00");

    // Display event information
    cout << "Event Information:\n";
    event.displayEventInfo();
    cout << "\n";

    return 0;
}