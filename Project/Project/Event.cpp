// Event.cpp
#include "Event.h"

using namespace std; 

Event::Event() {}     // Default constructor: No additional initialization required

Event::Event(const string& name, const string& date, const string& time)
    : name(name), date(date), time(time) {}     // Parameterized constructor: Initialize member variables with provided values

// Destructor
Event::~Event() {
    // Add any cleanup code if necessary
}

// Copy Constructor
Event::Event(const Event& other)
    : name(other.name), date(other.date), time(other.time) {}

// Copy Assignment Operator
Event& Event::operator=(const Event& other) {
    if (this != &other) {
        name = other.name;
        date = other.date;
        time = other.time;
    }
    return *this;
}

// Equality operator
bool Event::operator==(const Event& other) const {
    return (name == other.name) && (date == other.date) && (time == other.time);
}
const string& Event::getName() const {
    return name;  // Return the name of the event
}

const string& Event::getDate() const {
    return date;  // Return the date of the event
}

const string& Event::getTime() const {
    return time;  // Return the time of the event
}

void Event::setName(const string& name) {
    if (!name.empty()) {
        Event::name = name;  // Set the name of the event if it's not empty
    }
    else {
        cerr << "Invalid name\n";  // Display an error message if the name is empty
    }
}

void Event::setDate(const string& date) {
    if (!date.empty()) {
        Event::date = date;  // Set the date of the event if it's not empty
    }
    else {
        cerr << "Invalid date\n";  // Display an error message if the date is empty
    }
}

void Event::setTime(const string& time) {
    if (!time.empty()) {
        Event::time = time;  // Set the time of the event if it's not empty
    }
    else {
        cerr << "Invalid time\n";  // Display an error message if the time is empty
    }
}

void Event::displayEventInfo() const {
    cout << "Event Name: " << name << "\n";  // Display the name of the event
    cout << "Date: " << date << "\n";        // Display the date of the event
    cout << "Time: " << time << "\n";        // Display the time of the event
}