// EventTicket.cpp
#include "EventTicket.h"

// Default constructor
EventTicket::EventTicket() : Ticket(), eventDetails() {}

// Parameterized constructor
EventTicket::EventTicket(const string& category, const Event& eventDetails)
    : Ticket(category), eventDetails(eventDetails) {}

// Copy constructor
EventTicket::EventTicket(const EventTicket& other)
    : Ticket(other), eventDetails(other.eventDetails) {}

// Destructor
EventTicket::~EventTicket() {
    // If there are any additional cleanup operations, add them here
}

// Copy assignment operator
EventTicket& EventTicket::operator=(const EventTicket& other) {
    if (this != &other) {
        // Call the base class assignment operator
        Ticket::operator=(other);
        // Copy eventDetails
        eventDetails = other.eventDetails;
    }
    return *this;
}

// Implement the displayEventTicketInfo method
void EventTicket::displayEventTicketInfo() const {
    displayTicketInfo(); // Inherited method from Ticket class
    eventDetails.displayEventInfo(); // Display event details
}

// Implement the override of the abstract method
void EventTicket::abstractMethod() const {
    // Implementation of the abstract method
}