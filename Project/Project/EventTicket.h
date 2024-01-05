// EventTicket.h
#pragma once

#include "Ticket.h"
#include "Event.h" // Include the Event class

class EventTicket : public Ticket {
private:
    Event eventDetails;

public:
    // Constructors and Destructor

    // Default constructor
    EventTicket();

    // Parameterized constructor
    EventTicket(const string& category, const Event& eventDetails);

    // Copy constructor
    EventTicket(const EventTicket& other);

    // Destructor
    ~EventTicket();

    // Copy assignment operator
    EventTicket& operator=(const EventTicket& other);

    // Display information

    // Method to display information about the event ticket
    void displayEventTicketInfo() const;

    // Override abstract method
    void abstractMethod() const override;
};
