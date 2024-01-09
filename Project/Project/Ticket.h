// Ticket.h
#pragma once  

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Ticket {
private:
    string category;  
    int uniqueID;     
    static int nextID;  
    string userName;
    string userEmail;
    string eventName;
    int seatRow;
    int seatNumber;

public:

 
    Ticket(const Ticket& other);

    ~Ticket();
    
    Ticket() : uniqueID(nextID++), seatRow(-1), seatNumber(-1) {}
    Ticket(const string& category) : category(category), uniqueID(nextID++), seatRow(-1), seatNumber(-1) {}

    Ticket& operator=(const Ticket& other);

    bool operator==(const Ticket& other) const;

    const string& getCategory() const;
    int getUniqueID() const;
    void setCategory(const string& category);

    void setUserName(const string& userName);
    void setUserEmail(const string& userEmail);
    void setEventName(const string& eventName);
    void setSeat(int row, int number);

    string getUserName() const;
    string getUserEmail() const;
    string getEventName() const;
    int getSeatRow() const;
    int getSeatNumber() const;

    void displayTicketInfo() const;

    static int getNextID();
};