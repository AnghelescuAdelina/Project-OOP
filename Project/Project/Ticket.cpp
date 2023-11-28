// Ticket.cpp
#include "Ticket.h"

using namespace std;

int Ticket::nextID = 1;

Ticket::Ticket() : uniqueID(nextID++) {}

Ticket::Ticket(const string& category) : category(category), uniqueID(nextID++) {}

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
    cout << "Category: " << category << "\n";
    cout << "Unique ID: " << uniqueID << "\n";
}

int Ticket::getNextID() {
    return nextID;
}