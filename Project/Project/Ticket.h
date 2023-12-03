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

public:
    //Constructors
    Ticket();  // Default constructor declaration
    Ticket(const string& category);  // Parameterized constructor declaration
    Ticket(const Ticket& other); //Copy constructor
    
    //Destructor
    ~Ticket();

    //Assignment operator
    Ticket& operator=(const Ticket& other);

    // Accessor methods
    const string& getCategory() const;  // Accessor method to get the category of the ticket
    int getUniqueID() const;            // Accessor method to get the unique ID of the ticket

    // Validation methods
    void setCategory(const string& category);  // Validation method to set the category of the ticket

    // Other methods
    void displayTicketInfo() const;  // Method to display information about the ticket

    //Overloaded operators
    bool operator==(const Ticket& other) const; //Equility operator

    // Static method
    static int getNextID();  // Static method to get the next available unique ID
};