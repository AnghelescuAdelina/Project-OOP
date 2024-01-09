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
    vector<Event> events;  
    EventLocation eventlocation;   
    unordered_map<int, Ticket> ticketMap; 
    int nextTicketID; 
    int numRows;
    int seatsPerRow;
    char** seatAvailability;

public:

    TicketBookingApp(const string& eventFilename="eventsDetails.txt", const string& locationFilename="eventlocations.txt");

    void processFile(const string& filename);

    void createAndStoreTicket(const string& eventName, const string& ticketCategory,
        const string& userName, const string& userEmail);

    void bookTicket();

    void displayTicketDetails();

    void saveTicketsToFile(const string& filename) const;

    void loadEventsFromFile(const string& filename);

    void saveUserDetailsToFile(const Ticket& ticket, const string& filename);

    void displayEventList();

    void run();
};