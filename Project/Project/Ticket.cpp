// Ticket.cpp
#include "Ticket.h"

int Ticket::nextID = 1;

Ticket::Ticket() : uniqueID(nextID++) {}

Ticket::Ticket(const std::string& category) : category(category), uniqueID(nextID++) {}

const std::string& Ticket::getCategory() const {
    return category;
}

int Ticket::getUniqueID() const {
    return uniqueID;
}

void Ticket::setCategory(const std::string& category) {
    if (!category.empty()) {
        Ticket::category = category;
    }
    else {
        std::cerr << "Invalid category\n";
    }
}

void Ticket::displayTicketInfo() const {
    std::cout << "Category: " << category << "\n";
    std::cout << "Unique ID: " << uniqueID << "\n";
}

int Ticket::getNextID() {
    return nextID;
}