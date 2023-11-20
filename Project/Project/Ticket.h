// Ticket.h
#pragma once
#include <iostream>
#include <vector>

class Ticket {
private:
    std::string category;
    int uniqueID;
    static int nextID;

public:
    Ticket();
    Ticket(const std::string& category);

    // Accessor methods
    const std::string& getCategory() const;
    int getUniqueID() const;

    // Validation methods
    void setCategory(const std::string& category);

    // Other methods
    void displayTicketInfo() const;

    // Static method
    static int getNextID();
};