// EventLocation.cpp
#include "EventLocation.h"

using namespace std;  

// Default constructor: Initialize member variables to default values
EventLocation::EventLocation() : maxSeats(0), numRows(0), numZones(0) {}

EventLocation::EventLocation(int maxSeats, int numRows, int numZones, const vector<int>& seatsPerRow)
    : maxSeats(maxSeats), numRows(numRows), numZones(numZones), seatsPerRow(seatsPerRow) {}
// Parameterized constructor: Initialize member variables with provided values


int EventLocation::getMaxSeats() const {
    return maxSeats;  // Return the maximum number of seats
}

int EventLocation::getNumRows() const {
    return numRows;  // Return the number of rows
}

int EventLocation::getNumZones() const {
    return numZones;  // Return the number of zones
}

const std::vector<int>& EventLocation::getSeatsPerRow() const {
    return seatsPerRow;  // Return the vector containing the number of seats per row
}

void EventLocation::setMaxSeats(int maxSeats) {
    if (maxSeats > 0) {
        EventLocation::maxSeats = maxSeats;  // Set the maximum number of seats if it's a valid value
    }
    else {
        cerr << "Invalid maxSeats value\n";  // Display an error message if the value is not valid
    }
}

void EventLocation::setNumRows(int numRows) {
    if (numRows > 0) {
        EventLocation::numRows = numRows;  // Set the number of rows if it's a valid value
    }
    else {
        cerr << "Invalid numRows value\n";  // Display an error message if the value is not valid
    }
}

void EventLocation::setNumZones(int numZones) {
    if (numZones > 0) {
        EventLocation::numZones = numZones;  // Set the number of zones if it's a valid value
    }
    else {
        cerr << "Invalid numZones value\n";  // Display an error message if the value is not valid
    }
}

void EventLocation::setSeatsPerRow(const vector<int>& seatsPerRow) {
    if (!seatsPerRow.empty()) {
        EventLocation::seatsPerRow = seatsPerRow;  // Set the vector containing the number of seats per row if it's not empty
    }
    else {
        cerr << "Invalid seatsPerRow value\n";  // Display an error message if the value is not valid
    }
}

void EventLocation::displayLocationInfo() const {
    cout << "Max Seats: " << maxSeats << "\n";  // Display the maximum number of seats
    cout << "Num Rows: " << numRows << "\n";    // Display the number of rows
    cout << "Num Zones: " << numZones << "\n";  // Display the number of zones
    cout << "Seats Per Row: ";
    for (int seats : seatsPerRow) {
        cout << seats << " ";  // Display each element in the vector of seats per row
    }
    cout << "\n";
}