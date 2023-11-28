// Ticket.h
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Ticket {
private:
    string category;
    int uniqueID;
    static int nextID;

public:
    Ticket();
    Ticket(const string& category);

    // Accessor methods
    const string& getCategory() const;
    int getUniqueID() const;

    // Validation methods
    void setCategory(const string& category);

    // Other methods
    void displayTicketInfo() const;

    // Static method
    static int getNextID();
};