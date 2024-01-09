// EventLocation.h
#pragma once  

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class EventLocation {
private:
    int maxSeats;        
    int numRows;       
    int numZones;        
    int* seatsPerRow;  

public:
  
    EventLocation(const string& filename="eventLocations.txt");

    ~EventLocation();

    EventLocation(const EventLocation& other);

    EventLocation& operator=(const EventLocation& other);

    bool operator==(const EventLocation& other) const;
};