// EventLocation.cpp
#include "EventLocation.h"
#include <iostream>

using namespace std;

// Default constructor: Initialize member variables to default values
EventLocation::EventLocation() : maxSeats(0), numRows(0), numZones(0), seatsPerRow(nullptr) {}

// Parameterized constructor: Initialize member variables with provided values
EventLocation::EventLocation(int maxSeats, int numRows, int numZones, const int* seatsPerRow)
    : maxSeats(maxSeats), numRows(numRows), numZones(numZones) {
    // Allocate memory for seatsPerRow and copy values
    this->seatsPerRow = new int[numRows];
    for (int i = 0; i < numRows; ++i) {
        this->seatsPerRow[i] = seatsPerRow[i];
    }
}

// Destructor: Release dynamically allocated memory
EventLocation::~EventLocation() {
    delete[] seatsPerRow;
}

// Copy Constructor
EventLocation::EventLocation(const EventLocation& other)
    : maxSeats(other.maxSeats), numRows(other.numRows), numZones(other.numZones) {
    // Allocate memory for seatsPerRow and copy values
    this->seatsPerRow = new int[numRows];
    for (int i = 0; i < numRows; ++i) {
        this->seatsPerRow[i] = other.seatsPerRow[i];
    }
}

// Copy Assignment Operator
EventLocation& EventLocation::operator=(const EventLocation& other) {
    if (this != &other) {
        maxSeats = other.maxSeats;
        numRows = other.numRows;
        numZones = other.numZones;

        // Release existing memory
        delete[] seatsPerRow;

        // Allocate memory for seatsPerRow and copy values
        seatsPerRow = new int[numRows];
        for (int i = 0; i < numRows; ++i) {
            seatsPerRow[i] = other.seatsPerRow[i];
        }
    }
    return *this;
}

// Equality operator
bool EventLocation::operator==(const EventLocation& other) const {
    return (maxSeats == other.maxSeats) &&
        (numRows == other.numRows) &&
        (numZones == other.numZones);
    // Comparing seatsPerRow is not necessary for equality
}

int EventLocation::getMaxSeats() const {
    return maxSeats;
}

int EventLocation::getNumRows() const {
    return numRows;
}

int EventLocation::getNumZones() const {
    return numZones;
}

const int* EventLocation::getSeatsPerRow() const {
    return seatsPerRow;
}

void EventLocation::setMaxSeats(int maxSeats) {
    if (maxSeats > 0) {
        this->maxSeats = maxSeats;
    }
    else {
        cerr << "Invalid maxSeats value\n";
    }
}

void EventLocation::setNumRows(int numRows) {
    if (numRows > 0) {
        this->numRows = numRows;
    }
    else {
        cerr << "Invalid numRows value\n";
    }
}

void EventLocation::setNumZones(int numZones) {
    if (numZones > 0) {
        this->numZones = numZones;
    }
    else {
        cerr << "Invalid numZones value\n";
    }
}

void EventLocation::setSeatsPerRow(const int* seatsPerRow) {
    // Release existing memory
    delete[] this->seatsPerRow;

    // Allocate memory for seatsPerRow and copy values
    this->seatsPerRow = new int[numRows];
    for (int i = 0; i < numRows; ++i) {
        this->seatsPerRow[i] = seatsPerRow[i];
    }
}

void EventLocation::displayLocationInfo() const {
    cout << "Max Seats: " << maxSeats << "\n";
    cout << "Num Rows: " << numRows << "\n";
    cout << "Num Zones: " << numZones << "\n";
    cout << "Seats Per Row: ";
    for (int i = 0; i < numRows; ++i) {
        cout << seatsPerRow[i] << " ";
    }
    cout << "\n";
}