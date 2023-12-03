// Event.h
#pragma once  // Header guard to prevent multiple inclusions of the same header file

#include <iostream>  

using namespace std;   

class Event {
private:
    string name;  // Private member variable to store the name of the event
    string date;  // Private member variable to store the date of the event
    string time;  // Private member variable to store the time of the event

public:
    Event();  // Default constructor declaration
    Event(const string& name, const string& date, const string& time);  // Parameterized constructor declaration

    //Destructor
    ~Event();

    // Copy Constructor
    Event(const Event& other);  

    // Copy Assignment Operator
    Event& operator=(const Event& other);  


    // Accessor methods
    const string& getName() const;  // Accessor method to get the name of the event
    const string& getDate() const;  // Accessor method to get the date of the event
    const string& getTime() const;  // Accessor method to get the time of the event

    // Validation methods
    void setName(const string& name);  // Validation method to set the name of the event
    void setDate(const string& date);  // Validation method to set the date of the event
    void setTime(const string& time);  // Validation method to set the time of the event

    // Other methods
    void displayEventInfo() const;  // Method to display information about the event
    // Equality operator
    bool operator==(const Event& other) const;
};