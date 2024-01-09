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
    int numRows;
    int seatsPerRow;
    char** seatAvailability;

public:
    TicketBookingApp(); // Default constructor


    // Constructor
    TicketBookingApp(const string& eventFilename, const string& locationFilename)
        :eventlocation(locationFilename) {
        loadEventsFromFile(eventFilename);
    }

    // Method to process a file for ticket booking
    void processFile(const string& filename);

    // Method to create and store a ticket
    void createAndStoreTicket(const string& eventName, const string& ticketCategory,
        const string& userName, const string& userEmail);

    // Method to book a ticket
    void bookTicket();

    // Method to display ticket details
    void displayTicketDetails();

    // Method to save ticket details to a file
    void saveTicketsToFile(const string& filename) const;

    // Method to load events from a file
    void loadEventsFromFile(const string& filename);

    // Method to save user details to a file
    void saveUserDetailsToFile(const Ticket& ticket, const string& filename);
    
    //Method to display the list with the events
    void displayEventList();

    // Main method to run the application
    void run();

    // Destructor (if you need to manage resources, like dynamically allocated memory)
    ~TicketBookingApp();
    
};