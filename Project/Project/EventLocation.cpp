#include "EventLocation.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


// New constructor to initialize from a file
EventLocation::EventLocation(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file >> numRows;
    seatsPerRow = new int[numRows];

    int seatCount = 0;
    for (int i = 0; i < numRows; ++i) {
        int seatsInRow;
        file >> seatsInRow;
        seatsPerRow[i] = seatsInRow;
        seatCount += seatsInRow;
    }

    maxSeats = seatCount;
    numZones = 1;  // Assuming a single zone for simplicity
}

// Destructor: Release dynamically allocated memory
EventLocation::~EventLocation() {
    delete[] seatsPerRow;
}

// Copy Constructor
EventLocation::EventLocation(const EventLocation& other)
    : maxSeats(other.maxSeats), numRows(other.numRows), numZones(other.numZones) {
    seatsPerRow = new int[numRows];
    for (int i = 0; i < numRows; ++i) {
        seatsPerRow[i] = other.seatsPerRow[i];
    }
}

// Copy Assignment Operator
EventLocation& EventLocation::operator=(const EventLocation& other) {
    if (this != &other) {
        delete[] seatsPerRow;

        maxSeats = other.maxSeats;
        numRows = other.numRows;
        numZones = other.numZones;

        seatsPerRow = new int[numRows];
        for (int i = 0; i < numRows; ++i) {
            seatsPerRow[i] = other.seatsPerRow[i];
        }
    }
    return *this;
}

