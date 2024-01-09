// Event.cpp
#include "Event.h"

using namespace std;

Event::Event(const string& name, const string& date, const string& time)
    : name(name), date(date), time(time) {}

Event::~Event() {
  
}

Event::Event(const Event& other)
    : name(other.name), date(other.date), time(other.time) {}

Event& Event::operator=(const Event& other) {
    if (this != &other) {
        name = other.name;
        date = other.date;
        time = other.time;
    }
    return *this;
}

bool Event::operator==(const Event& other) const {
    return (name == other.name) && (date == other.date) && (time == other.time);
}

const string& Event::getName() const {
    return name;
}

void Event::setDate(const string& date) {
    if (!date.empty()) {
        this->date = date;
    }
    else {
        cerr << "Invalid date\n";
    }
}

void Event::setTime(const string& time) {
    if (!time.empty()) {
        this->time = time;
    }
    else {
        cerr << "Invalid time\n";
    }
}

void Event::displayEventInfo() const {
    cout << "Event Name: " << name << "\n";
    cout << "Date: " << date << "\n";
    cout << "Time: " << time << "\n";
}