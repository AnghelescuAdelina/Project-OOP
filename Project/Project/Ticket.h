// Ticket.h
#pragma once  // Header guard to prevent multiple inclusions of the same header file

#include <iostream>  
#include <vector>    // Include necessary standard C++ library for vectors

using namespace std;  

class Ticket {
private:
    string category;  // Private member variable to store the category of the ticket
    int uniqueID;     // Private member variable to store the unique ID of the ticket
    static int nextID;  // Static member variable to keep track of the next available unique ID

public:
    Ticket();  // Default constructor declaration
    Ticket(const string& category);  // Parameterized constructor declaration

    // Accessor methods
    const string& getCategory() const;  // Accessor method to get the category of the ticket
    int getUniqueID() const;            // Accessor method to get the unique ID of the ticket

    // Validation methods
    void setCategory(const string& category);  // Validation method to set the category of the ticket

    // Other methods
    void displayTicketInfo() const;  // Method to display information about the ticket

    // Static method
    static int getNextID();  // Static method to get the next available unique ID
};