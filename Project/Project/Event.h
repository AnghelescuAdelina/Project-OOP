// Event.h
#pragma once

#include <iostream>

using namespace std;

class Event {
public:
    string name;
    string date;
    string time;

public:
    // Constructors and Destructor

    // Default constructor
    Event();

    // Parameterized constructor
    Event(const string& name, const string& date, const string& time);

    // Destructor
    ~Event();

    // Copy Constructor
    Event(const Event& other);

    // Copy Assignment Operator
    Event& operator=(const Event& other);

    // Equality operator
    bool operator==(const Event& other) const;

    // Accessors

    // Getter for name
    const string& getName() const;

    // Getter for date
    const string& getDate() const;

    // Getter for time
    const string& getTime() const;

    // Validation methods

    // Setter for name
    void setName(const string& name);

    // Setter for date
    void setDate(const string& date);

    // Setter for time
    void setTime(const string& time);

    // Display information

    // Display information about the event
    void displayEventInfo() const;
};
