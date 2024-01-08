// Event.cpp
#include "Event.h"

using namespace std;

// Default constructor: No additional initialization required
Event::Event() {}

// Parameterized constructor: Initialize member variables with provided values
Event::Event(const string& name, const string& date, const string& time)
    : name(name), date(date), time(time) {}

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

// Getter for name
const string& Event::getName() const {
    return name;
}

// Getter for date
const string& Event::getDate() const {
    return date;
}

// Getter for time
const string& Event::getTime() const {
    return time;
}

// Setter for name
void Event::setName(const string& name) {
    if (!name.empty()) {
        this->name = name;
    }
    else {
        cerr << "Invalid name\n";
    }
}

// Setter for date
void Event::setDate(const string& date) {
    if (!date.empty()) {
        this->date = date;
    }
    else {
        cerr << "Invalid date\n";
    }
}

// Setter for time
void Event::setTime(const string& time) {
    if (!time.empty()) {
        this->time = time;
    }
    else {
        cerr << "Invalid time\n";
    }
}

// Display information about the event
void Event::displayEventInfo() const {
    cout << "Event Name: " << name << "\n";
    cout << "Date: " << date << "\n";
    cout << "Time: " << time << "\n";
}

//Implementation of the operator >>
istream& operator>>(istream& input, Event& event) {
    input >> event.name >> event.date >> event.time;
    return input;
}