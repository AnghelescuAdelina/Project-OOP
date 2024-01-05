// Ticket.h
#pragma once  // Header guard to prevent multiple inclusions of the same header file

#include <iostream>
#include <string>
#include "AbstractTicket.h" // Include the abstract class header

using namespace std;

class Ticket {
private:
    string category;  // Private member variable to store the category of the ticket
    int uniqueID;     // Private member variable to store the unique ID of the ticket
    static int nextID;  // Static member variable to keep track of the next available unique ID

public:
    // Constructors and Destructor

    // Default constructor declaration
    Ticket();

    // Parameterized constructor declaration
    Ticket(const string& category);

    // Copy constructor declaration
    Ticket(const Ticket& other);

    // Destructor declaration
    ~Ticket();

    // Assignment and Equality operators

    // Copy assignment operator
    Ticket& operator=(const Ticket& other);

    // Equality operator
    bool operator==(const Ticket& other) const;

    // Accessors

    // Accessor method to get the category of the ticket
    const string& getCategory() const;

    // Accessor method to get the unique ID of the ticket
    int getUniqueID() const;

    // Validation method

    // Validation method to set the category of the ticket
    void setCategory(const string& category);

    // Display information

    // Method to display information about the ticket
    void displayTicketInfo() const;

    // Static method

    // Static method to get the next available unique ID
    static int getNextID();
};