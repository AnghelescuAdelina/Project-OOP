// TicketBookingApp.h
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "EventLocation.h"
#include "Event.h"
#include "Ticket.h"

class TicketBookingApp {
private:
    std::vector<Event> events;  // Store a list of events
    EventLocation location;     // Store event location details
    std::vector<Ticket> tickets;  // Store issued tickets

    // Helper functions for managing events and tickets
    void loadEventsFromFile(const std::string& filename);
    void saveTicketsToFile(const std::string& filename);

public:
    // Constructor
    TicketBookingApp(const std::string& eventFilename, const std::string& locationFilename);

    // Public methods for user interaction
    void run();
    void displayEventList() const;
    void bookTicket();
    void displayTicketList() const;
    // Add more public methods as needed for menu options

    // Destructor
    ~TicketBookingApp();
};