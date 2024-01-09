// TicketBookingApp.h
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "EventLocation.h"
#include "Event.h"
#include "Ticket.h"

using namespace std;

class TicketBookingApp {
private:
    vector<Event> events;  // Store a list of events
    EventLocation eventlocation;     // Store event location details
    unordered_map<int, Ticket> ticketMap; // Mapping of ticket ID to Ticket object
    int nextTicketID; //To keep track of the next available unique ticket ID

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
    void displayTicketDetails();
    void saveTicketsToFile(const std::string& filename) const;
    void loadTicketsFromFile(const std::string& filename);
    
};