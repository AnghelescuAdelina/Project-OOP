// TicketBookingApp.h
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "EventLocation.h"
#include "Event.h"
#include "Ticket.h"

using namespace std;

class TicketBookingApp {
private:
    vector<Event> events;  // Store a list of events
    EventLocation location;     // Store event location details
    vector<Ticket> tickets;  // Store issued tickets

    // Helper functions for managing events and tickets
    void loadEventsFromFile(const string& filename);
    void saveTicketsToFile(const string& filename);

public:
    // Constructor
    TicketBookingApp(const string& eventFilename, const string& locationFilename);

    // Public methods for user interaction
    void run();
    void displayEventList() const;
    void bookTicket();
    void displayTicketList() const;
    // Add more public methods as needed for menu options

    // Destructor
    ~TicketBookingApp();
};