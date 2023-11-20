// EventLocation.h
#pragma once  //prevent a header file from being included more than once in a translation unit
#include <iostream>
#include <vector>

class EventLocation {
private: 
    int maxSeats;
    int numRows;
    int numZones;
    std::vector<int> seatsPerRow;

public:
    EventLocation();
    EventLocation(int maxSeats, int numRows, int numZones, const std::vector<int>& seatsPerRow);

    // Accessor methods
    int getMaxSeats() const;
    int getNumRows() const;
    int getNumZones() const;
    const std::vector<int>& getSeatsPerRow() const;

    // Validation methods
    void setMaxSeats(int maxSeats);
    void setNumRows(int numRows);
    void setNumZones(int numZones);
    void setSeatsPerRow(const std::vector<int>& seatsPerRow);

    // Other methods
    void displayLocationInfo() const;
};