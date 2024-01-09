// Ticket.cpp
#include "Ticket.h"

using namespace std;

int Ticket::nextID = 1;

Ticket::~Ticket() {}

Ticket::Ticket(const Ticket& other) : category(other.category), uniqueID(nextID++) {}

Ticket& Ticket::operator=(const Ticket& other) {
    if (this != &other) {
        category = other.category;
        uniqueID = nextID++;
    }
    return *this; 
}

bool Ticket::operator==(const Ticket& other) const {
    return (category == other.category) && (uniqueID == other.uniqueID);
}

const string& Ticket::getCategory() const {
    return category;
}

int Ticket::getUniqueID() const {
    return uniqueID;
}

void Ticket::setCategory(const string& category) {
    if (!category.empty()) {
        Ticket::category = category;
    }
    else {
        cerr << "Invalid category\n";
    }
}

void Ticket::displayTicketInfo() const {
    cout << "Username: " << userName << "\n";
    cout << "Event Name: " << eventName << "\n";
    cout << "Category: " << category << "\n";   
    cout << "Unique ID: " << uniqueID << "\n";  
    cout << "Seat number: " << seatNumber << "\n";
    cout << "Row: " << seatRow << "\n";
}

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