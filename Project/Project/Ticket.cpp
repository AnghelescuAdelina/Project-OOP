// Ticket.cpp
#include "Ticket.h"

using namespace std;

// Initialize the static member variable 'nextID' to 1
int Ticket::nextID = 1;

// Default constructor: Increment the nextID and assign it to uniqueID
Ticket::Ticket() : uniqueID(nextID++) {}

// Parameterized constructor: Assign the provided category, increment nextID, and assign it to uniqueID
Ticket::Ticket(const string& category) : category(category), uniqueID(nextID++) {}

// Destructor: No dynamic memory to deallocate, so no specific cleanup needed
Ticket::~Ticket() {}

// Copy constructor: Copy the 'category' from 'other' and generate a new unique ID
Ticket::Ticket(const Ticket& other) : category(other.category), uniqueID(nextID++) {}

// Copy assignment operator
Ticket& Ticket::operator=(const Ticket& other) {
    if (this != &other) {
        // Check for self-assignment
        // Copy data from 'other' to 'this'
        category = other.category;
        uniqueID = nextID++;
    }
    return *this; // Return the modified object
}

// Equality operator
bool Ticket::operator==(const Ticket& other) const {
    return (category == other.category) && (uniqueID == other.uniqueID);
    // Check if the category and unique ID of two tickets are equal
}

// Accessor method to get the category of the ticket
const string& Ticket::getCategory() const {
    return category;
}

// Accessor method to get the unique ID of the ticket
int Ticket::getUniqueID() const {
    return uniqueID;
}

// Validation method to set the category of the ticket
void Ticket::setCategory(const string& category) {
    if (!category.empty()) {
        Ticket::category = category;
    }
    else {
        cerr << "Invalid category\n";
    }
}

// Method to display information about the ticket
void Ticket::displayTicketInfo() const {
    cout << "Category: " << category << "\n";    // Display the category of the ticket
    cout << "Unique ID: " << uniqueID << "\n";   // Display the unique ID of the ticket
}

// Static method to get the next available unique ID
int Ticket::getNextID() {
    return nextID;
}

void Ticket::setUserName(const string& userName) {
    this->userName = userName;
}

void Ticket::setUserEmail(const string& userEmail) {
    this->userEmail = userEmail;
}

void Ticket::setEventName(const string& eventName) {
    this->eventName = eventName;
}

void Ticket::setSeat(int row, int number) {
    seatRow = row;
    seatNumber = number;
}

string Ticket::getUserName() const {
    return userName;
}

string Ticket::getUserEmail() const {
    return userEmail;
}

string Ticket::getEventName() const {
    return eventName;
}

int Ticket::getSeatRow() const {
    return seatRow;
}

int Ticket::getSeatNumber() const {
    return seatNumber;
}