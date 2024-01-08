// EventLocation.cpp
#include "EventLocation.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Default constructor: Initialize member variables to default values
EventLocation::EventLocation() : maxSeats(0), numRows(0), numZones(0), seatsPerRow(nullptr) {}

// Parameterized constructor: Initialize member variables with provided values
EventLocation::EventLocation(int maxSeats, int numRows, int numZones, const vector<int>& seatsPerRow)
    : maxSeats(maxSeats), numRows(numRows), numZones(numZones), seatsPerRow(seatsPerRow){
    
    }

// Destructor: Release dynamically allocated memory
EventLocation::~EventLocation() {

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
        seatsPerRow = other.seatsPerRow;  // Use vector's copy assignment
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

    //Defined the >> operator for ifstream
    istream& operator>>(istream & input, EventLocation & eventLocation) {
        // Read maxSeats, numRows, and numZones from the input stream
        input >> eventLocation.maxSeats >> eventLocation.numRows >> eventLocation.numZones;

        // Read seatsPerRow values from the input stream
        eventLocation.seatsPerRow.resize(eventLocation.numRows);
        for (int i = 0; i < eventLocation.numRows; ++i) {
            input >> eventLocation.seatsPerRow[i];
        }

        return input;
    }
}