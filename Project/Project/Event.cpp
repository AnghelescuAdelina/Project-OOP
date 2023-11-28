// Event.cpp
#include "Event.h"

using namespace std;

Event::Event() {}

Event::Event(const string& name, const string& date, const string& time)
    : name(name), date(date), time(time) {}

const string& Event::getName() const {
    return name;
}

const string& Event::getDate() const {
    return date;
}

const string& Event::getTime() const {
    return time;
}

void Event::setName(const string& name) {
    if (!name.empty()) {
        Event::name = name;
    }
    else {
        cerr << "Invalid name\n";
    }
}

void Event::setDate(const string& date) {
    if (!date.empty()) {
        Event::date = date;
    }
    else {
        cerr << "Invalid date\n";
    }
}

void Event::setTime(const string& time) {
    if (!time.empty()) {
        Event::time = time;
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