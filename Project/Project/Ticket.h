// Ticket.h
#pragma once  // Header guard to prevent multiple inclusions of the same header file

#include <iostream>
#include <string>

using namespace std;

class Ticket {
private:
    string category;  // Private member variable to store the category of the ticket
    int uniqueID;     // Private member variable to store the unique ID of the ticket
    static int nextID;  // Static member variable to keep track of the next available unique ID
    string userName;
    string userEmail;
    string eventName;
    int seatRow;
    int seatNumber;

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

    // Accessors and Mutators
    const string& getCategory() const;
    int getUniqueID() const;
    void setCategory(const string& category);

    // New methods to set user details and event details
    void setUserName(const string& userName);
    void setUserEmail(const string& userEmail);
    void setEventName(const string& eventName);
    void setSeat(int row, int number);

    // Method to get user and event details (if needed)
    string getUserName() const;
    string getUserEmail() const;
    string getEventName() const;
    int getSeatRow() const;
    int getSeatNumber() const;

    // Display information
    void displayTicketInfo() const;

    // Static method
    static int getNextID();
};