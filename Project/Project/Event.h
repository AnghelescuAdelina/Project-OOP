// Event.h
#pragma once
#include <iostream>

class Event {
private:
    std::string name;
    std::string date;
    std::string time;

public:
    Event();
    Event(const std::string& name, const std::string& date, const std::string& time);

    // Accessor methods
    const std::string& getName() const;
    const std::string& getDate() const;
    const std::string& getTime() const;

    // Validation methods
    void setName(const std::string& name);
    void setDate(const std::string& date);
    void setTime(const std::string& time);

    // Other methods
    void displayEventInfo() const;
};