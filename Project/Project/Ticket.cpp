// Ticket.cpp
#include "Ticket.h"

using namespace std;  

int Ticket::nextID = 1;  // Static member variable initialization, starting from 1

// Default constructor: Increment the nextID and assign it to uniqueID
Ticket::Ticket() : uniqueID(nextID++) {}
    
// Parameterized constructor: Assign the provided category, increment nextID, and assign it to uniqueID
Ticket::Ticket(const string& category) : category(category), uniqueID(nextID++) {}

const string& Ticket::getCategory() const {
    return category;  // Return the category of the ticket
}

int Ticket::getUniqueID() const {
    return uniqueID;  // Return the unique ID of the ticket
}

void Ticket::setCategory(const string& category) {
    if (!category.empty()) {
        Ticket::category = category;  // Set the category if it is not empty
    }
    else {
        cerr << "Invalid category\n";  // Display an error message to standard error if the category is empty
    }
}

void Ticket::displayTicketInfo() const {
    cout << "Category: " << category << "\n";    // Display the category of the ticket
    cout << "Unique ID: " << uniqueID << "\n";   // Display the unique ID of the ticket
}

int Ticket::getNextID() {
    return nextID;  // Return the next available unique ID
}