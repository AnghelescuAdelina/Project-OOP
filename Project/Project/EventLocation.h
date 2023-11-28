// EventLocation.h
#pragma once  //prevent a header file from being included more than once in a translation unit
#include <iostream>
#include <vector>

using namespace std;

class EventLocation {
private: 
    int maxSeats;
    int numRows;
    int numZones;
    vector<int> seatsPerRow;

public:
    EventLocation();
    EventLocation(int maxSeats, int numRows, int numZones, const vector<int>& seatsPerRow);

    // Accessor methods
    int getMaxSeats() const;
    int getNumRows() const;
    int getNumZones() const;
    const vector<int>& getSeatsPerRow() const;

    // Validation methods
    void setMaxSeats(int maxSeats);
    void setNumRows(int numRows);
    void setNumZones(int numZones);
    void setSeatsPerRow(const vector<int>& seatsPerRow);

    // Other methods
    void displayLocationInfo() const;
};