// TicketBookingApp.cpp
#include "TicketBookingApp.h"

using namespace std;

// Constructor to initialize events and location
TicketBookingApp::TicketBookingApp(const string& eventFilename, const string& locationFilename)
    :eventlocation(0, 0, 0, {}) {
    // Load events from event file (similar to loadEventsFromFile)
   // Load event location matrix from location file
   // Initialize ticket-related variables
    nextTicketID = 1;
}

void TicketBookingApp::displayTicketDetails() {
    int ticketID;
    cout << "Enter the ticket ID: ";
    cin >> ticketID;

    auto it = ticketMap.find(ticketID);
    if (it != ticketMap.end()) {
        Ticket& ticket = it->second;
        // Display ticket details
        ticket.displayTicketInfo();
    }
    else {
        cerr << "Ticket not found with ID: " << ticketID << endl;
    }
}
void TicketBookingApp::saveTicketsToFile(const string& filename) const {
    // Save ticket details to a file (e.g., ticket ID, name, event details, etc.)
    // ...
}

void TicketBookingApp::loadEventsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string name, date, time;
    while (file >> name >> date >> time) {
        events.push_back(Event(name, date, time));
    }
    file.close();
}

void TicketBookingApp::run() {
    int choice;
    while (true) {
        cout << "1. View Events\n";
        cout << "2. Book Ticket\n";
        cout << "3.Display Ticket Details\n";
        cout << "4.Exit\n";
        cout<<"5.Enter choice : ";
        cin >> choice;
        switch (choice) {
        case 1: displayEventList(); break;
        case 2: bookTicket(); break;
        case 3: displayTicketDetails(); break;
        case 4: return;
        default: cout << "Invalid choice.\n";
        }
    }
}
char** seatAvailability;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        // Example: Check if the argument is a filename for file processing
        string filename = argv[1];
        // Process the file...
    }
    else {
        // Run the application in menu-driven mode
        TicketBookingApp app;
        app.run();
    }
    return 0;
}
