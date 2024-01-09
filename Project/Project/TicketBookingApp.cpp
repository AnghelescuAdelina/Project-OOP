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
void TicketBookingApp::createAndStoreTicket(const string& eventName, const string& ticketCategory, const string& userName, const string& userEmail) {
    // Find the event in the events list
    auto it = find_if(events.begin(), events.end(), [&eventName](const Event& event) {
        return event.getName() == eventName;
        });

    if (it != events.end()) {
        // Event found
        Event& event = *it;

        // This is a simplified version, modify according to your seat matrix logic
        int seatRow = -1, seatNumber = -1;
        for (int row = 0; row < numRows; ++row) {
            for (int seat = 0; seat < seatsPerRow; ++seat) {
                if (seatAvailability[row][seat] == 0) { // Assuming 0 means available
                    seatRow = row;
                    seatNumber = seat;
                    seatAvailability[row][seat] = 1; // Mark as taken
                    break;
                }
            }
            if (seatRow != -1) break;
        }

        if (seatRow == -1) {
            cout << "No available seats for " << eventName << endl;
            return;
        }

        // Create a Ticket object with the provided details
        Ticket newTicket(ticketCategory);
        newTicket.setUserName(userName); // Assuming these methods exist in Ticket class
        newTicket.setUserEmail(userEmail);
        newTicket.setEventName(eventName); // Set event name
        newTicket.setSeat(seatRow, seatNumber); // Set seat details

        // Add the Ticket to the ticketMap
        ticketMap[nextTicketID] = newTicket;
        cout << "Ticket booked successfully. Ticket ID: " << nextTicketID << endl;

        // Increment the ticket ID for the next ticket
        nextTicketID++;
    }
    else {
        // Event not found
        cerr << "Event not found: " << eventName << endl;
    }
}
void TicketBookingApp::saveUserDetailsToFile(const Ticket& ticket, const string& filename) {
    ofstream outFile(filename, ios::app);  // Open in append mode to add to the file
    if (!outFile) {
        cerr << "Failed to open file for writing user details: " << filename << endl;
        return;
    }

    outFile << ticket.getUserName() << " " << ticket.getUserEmail() << "\n";
    outFile.close();
}
void TicketBookingApp::bookTicket() {
    string eventName, userName, userEmail, ticketCategory;
    cout << "Enter Event Name: ";
    cin >> eventName;
    cout << "Enter Ticket Category: ";
    cin >> ticketCategory;
    cout << "Enter User Name: ";
    cin >> userName;
    cout << "Enter User Email: ";
    cin >> userEmail;

    // Now, create and store the ticket with all details
    createAndStoreTicket(eventName, ticketCategory, userName, userEmail);
}
void TicketBookingApp::processFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string eventName, ticketCategory;
    while (file >> eventName >> ticketCategory) {
        createAndStoreTicket(eventName, ticketCategory, "", "");  // Empty strings for userName and userEmail
    }

    file.close();
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
    TicketBookingApp app;
    if (argc > 1) {
        string filename = argv[1];
        app.processFile(filename);
    }
    else {
        app.run();
    }
    return 0;
}

