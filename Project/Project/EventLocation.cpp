// EventLocation.cpp
#include "EventLocation.h"

EventLocation::EventLocation() : maxSeats(0), numRows(0), numZones(0) {}

EventLocation::EventLocation(int maxSeats, int numRows, int numZones, const std::vector<int>& seatsPerRow)
    : maxSeats(maxSeats), numRows(numRows), numZones(numZones), seatsPerRow(seatsPerRow) {}

int EventLocation::getMaxSeats() const {
    return maxSeats;
}

int EventLocation::getNumRows() const {
    return numRows;
}

int EventLocation::getNumZones() const {
    return numZones;
}

const std::vector<int>& EventLocation::getSeatsPerRow() const {
    return seatsPerRow;
}

void EventLocation::setMaxSeats(int maxSeats) {
    if (maxSeats > 0) {
        EventLocation::maxSeats = maxSeats;
    }
    else {
        std::cerr << "Invalid maxSeats value\n";
    }
}

void EventLocation::setNumRows(int numRows) {
    if (numRows > 0) {
        EventLocation::numRows = numRows;
    }
    else {
        std::cerr << "Invalid numRows value\n";
    }
}

void EventLocation::setNumZones(int numZones) {
    if (numZones > 0) {
        EventLocation::numZones = numZones;
    }
    else {
        std::cerr << "Invalid numZones value\n";
    }
}

void EventLocation::setSeatsPerRow(const std::vector<int>& seatsPerRow) {
    if (!seatsPerRow.empty()) {
        EventLocation::seatsPerRow = seatsPerRow;
    }
    else {
        std::cerr << "Invalid seatsPerRow value\n";
    }
}

void EventLocation::displayLocationInfo() const {
    std::cout << "Max Seats: " << maxSeats << "\n";
    std::cout << "Num Rows: " << numRows << "\n";
    std::cout << "Num Zones: " << numZones << "\n";
    std::cout << "Seats Per Row: ";
    for (int seats : seatsPerRow) {
        std::cout << seats << " ";
    }
    std::cout << "\n";
}