// TicketBookingApp.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "TicketBookingApp.h"
#include "EventLocation.h"
#include "Event.h"
#include "Ticket.h"

using namespace std;

TicketBookingApp::TicketBookingApp(const string& eventFilename, const string& locationFilename)
    :eventlocation(locationFilename) {
    loadEventsFromFile(eventFilename);
}

void TicketBookingApp::createAndStoreTicket(const string& eventName, const string& ticketCategory, const string& userName, const string& userEmail) {
    auto it = find_if(events.begin(), events.end(), [&eventName](const Event& event) {
        return event.getName() == eventName;
        });
    int seatRow = -1;
    int seatNumber = -1;
    if (it != events.end()) {
        Event& event = *it;

        for (int row = 0; row < numRows; ++row) {
            for (int seat = 0; seat < seatsPerRow; ++seat) {
                if (seatAvailability[row][seat] == 0) { 
                    seatRow = row;
                    seatNumber = seat;
                    seatAvailability[row][seat] = 1; 
                    break;
                }
            }
            if (seatRow != -1) break;
        }

        if (seatRow == -1) {
            cout << "No available seats for " << eventName << endl;
            return;
        }

        Ticket newTicket(ticketCategory);
        newTicket.setUserName(userName);
        newTicket.setUserEmail(userEmail);
        newTicket.setEventName(eventName); 
        newTicket.setSeat(seatRow, seatNumber); 

        ticketMap[nextTicketID] = newTicket;
        cout << "Ticket booked successfully. Ticket ID: " << nextTicketID << endl;

        nextTicketID++;
    }
    else {

        cerr << "Event not found: " << eventName << endl;
    }
}
void TicketBookingApp::saveUserDetailsToFile(const Ticket& ticket, const string& SavedUserDetails) {
    ofstream outFile("SavedUserDetails", ios::app);
    if (!outFile) {
        cerr << "Failed to open file for writing user details: " << SavedUserDetails << endl;
        return;
    }

    outFile << ticket.getUserName() << " " << ticket.getUserEmail() << "\n";
    outFile.close();
}
void TicketBookingApp::bookTicket() {
    string eventName, ticketCategory, userName, userEmail;
    cout << "Enter Event Name: ";
    cin.ignore();
    getline(cin, eventName);
    cout << "Enter Ticket Category: ";
    cin >> ticketCategory;
    cin.ignore();
    cout << "Enter User Name: ";
    getline(cin, userName);
    cout << "Enter User Email: ";
    cin >> userEmail;

    createAndStoreTicket(eventName, ticketCategory, userName, userEmail);
}
void TicketBookingApp::processFile(const string& eventDetails) {
    ifstream file(eventDetails);
    if (!file) {
        cerr << "Failed to open file: " <<eventDetails << endl;
        return;
    }

    string eventName, ticketCategory;
    while (file >> eventName >> ticketCategory) {
        createAndStoreTicket(eventName, ticketCategory, "", "");  
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
        ticket.displayTicketInfo();
    }
    else {
        cerr << "Ticket not found with ID: " << ticketID << endl;
    }
}
void TicketBookingApp::saveTicketsToFile(const string& filename) const {
    ofstream outFile("savedTickets", ios::app);
}
void TicketBookingApp::loadEventsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: eventsDetails " << endl;
        return;
    }
    string name, date, time;
    while (getline(file, name)) {
        if (name.empty()) continue; 
        getline(file, date);
        getline(file, time);
        events.push_back(Event(name, date, time));
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    file.close();
}

void TicketBookingApp::displayEventList() {
    for (auto event : events)
        event.displayEventInfo();
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

