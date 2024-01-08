// EventLocation.h
#pragma once  // Header guard to prevent multiple inclusions of the same header file

#include <iostream>
#include <vector>
#include <string>

class EventLocation {
private:
    int maxSeats;        // Private member variable to store the maximum number of seats in the event location
    int numRows;         // Private member variable to store the number of rows in the event location
    int numZones;        // Private member variable to store the number of zones in the event location
    vector<int> seatsPerRow; // Use vector instead of dynamic array

public:

    // Constructors and Destructor

    // Default constructor
    EventLocation();

    // Parameterized constructor
    EventLocation(int maxSeats, int numRows, int numZones, const int* seatsPerRow);

    // Destructor
    ~EventLocation();

    // Copy constructor
    EventLocation(const EventLocation& other);

    // Copy Assignment Operator
    EventLocation& operator=(const EventLocation& other);

    // Equality operator
    bool operator==(const EventLocation& other) const;

    // Accessors

    // Accessor method to get the maximum number of seats
    int getMaxSeats() const;

    // Accessor method to get the number of rows
    int getNumRows() const;

    // Accessor method to get the number of zones
    int getNumZones() const;

    // Accessor method to get the array containing the number of seats per row
    const int* getSeatsPerRow() const;

    // Validation methods

    // Validation method to set the maximum number of seats
    void setMaxSeats(int maxSeats);

    // Validation method to set the number of rows
    void setNumRows(int numRows);

    // Validation method to set the number of zones
    void setNumZones(int numZones);

    // Validation method to set the array containing the number of seats per row
    void setSeatsPerRow(const int* seatsPerRow);

    // Display information

    // Method to display information about the event location
    void displayLocationInfo() const;

    // Method to check if a seat is available
    bool isSeatAvailable(int row, int zone, const string& category) const;

    //Defined the >> operator for ifstream
    friend std::istream& operator>>(std::istream& input, EventLocation& eventLocation);
};
