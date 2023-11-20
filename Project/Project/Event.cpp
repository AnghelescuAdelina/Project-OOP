// Event.cpp
#include "Event.h"

Event::Event() {}

Event::Event(const std::string& name, const std::string& date, const std::string& time)
    : name(name), date(date), time(time) {}

const std::string& Event::getName() const {
    return name;
}

const std::string& Event::getDate() const {
    return date;
}

const std::string& Event::getTime() const {
    return time;
}

void Event::setName(const std::string& name) {
    if (!name.empty()) {
        Event::name = name;
    }
    else {
        std::cerr << "Invalid name\n";
    }
}

void Event::setDate(const std::string& date) {
    if (!date.empty()) {
        Event::date = date;
    }
    else {
        std::cerr << "Invalid date\n";
    }
}

void Event::setTime(const std::string& time) {
    if (!time.empty()) {
        Event::time = time;
    }
    else {
        std::cerr << "Invalid time\n";
    }
}

void Event::displayEventInfo() const {
    std::cout << "Event Name: " << name << "\n";
    std::cout << "Date: " << date << "\n";
    std::cout << "Time: " << time << "\n";
}