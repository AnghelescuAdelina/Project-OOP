// EventLocation.h
#pragma once  // Header guard to prevent multiple inclusions of the same header file

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class EventLocation {
private:
    int maxSeats;        // Private member variable to store the maximum number of seats in the event location
    int numRows;         // Private member variable to store the number of rows in the event location
    int numZones;        // Private member variable to store the number of zones in the event location
    int* seatsPerRow;    // Private member variable to store the number of seats per row in the event location

public:
    // Constructors and Destructor

    // Parameterized constructor
    EventLocation(const string& filename="eventLocations.txt");

    // Destructor
    ~EventLocation();

    // Copy constructor
    EventLocation(const EventLocation& other);

    // Copy Assignment Operator
    EventLocation& operator=(const EventLocation& other);

    // Equality operator
    bool operator==(const EventLocation& other) const;
};