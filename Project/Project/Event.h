// Event.h
#pragma once
#include <iostream>

using namespace std;

class Event {
private:
   string name;
   string date;
   string time;

public:
    Event();
    Event(const string& name, const string& date, const string& time);

    // Accessor methods
    const string& getName() const;
    const string& getDate() const;
    const string& getTime() const;

    // Validation methods
    void setName(const string& name);
    void setDate(const string& date);
    void setTime(const string& time);

    // Other methods
    void displayEventInfo() const;
};