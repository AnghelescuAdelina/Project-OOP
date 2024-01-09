// Event.h
#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Event {
private:
    string name;
    string date;
    string time;

public:

    Event(const string& name, const string& date, const string& time);

    ~Event();

    Event(const Event& other);

    Event& operator=(const Event& other);

    bool operator==(const Event& other) const;

    const string& getName() const;

    const string& getDate() const;

    const string& getTime() const;

    void setName(const string& name);

    void setDate(const string& date);

    void setTime(const string& time);

    void displayEventInfo() const;
};