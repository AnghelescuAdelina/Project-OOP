// EventLocation.h
#pragma once  // Header guard to prevent multiple inclusions of the same header file

#include <iostream>  
#include <vector>    // Include necessary standard C++ library for vectors

using namespace std;  

class EventLocation {
private:
    int maxSeats;           // Private member variable to store the maximum number of seats in the event location
    int numRows;            // Private member variable to store the number of rows in the event location
    int numZones;           // Private member variable to store the number of zones in the event location
    vector<int> seatsPerRow;  // Private member variable to store the number of seats per row in the event location

public:
    EventLocation();  // Default constructor declaration
    EventLocation(int maxSeats, int numRows, int numZones, const vector<int>& seatsPerRow);  // Parameterized constructor declaration

    // Accessor methods
    int getMaxSeats() const;                  // Accessor method to get the maximum number of seats
    int getNumRows() const;                   // Accessor method to get the number of rows
    int getNumZones() const;                  // Accessor method to get the number of zones
    const vector<int>& getSeatsPerRow() const;  // Accessor method to get the number of seats per row

    // Validation methods
    void setMaxSeats(int maxSeats);               // Validation method to set the maximum number of seats
    void setNumRows(int numRows);                 // Validation method to set the number of rows
    void setNumZones(int numZones);               // Validation method to set the number of zones
    void setSeatsPerRow(const vector<int>& seatsPerRow);  // Validation method to set the number of seats per row

    // Other methods
    void displayLocationInfo() const;  // Method to display information about the event location
};