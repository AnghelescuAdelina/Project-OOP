// AbstractTicket.h
#pragma once

#include <iostream>
#include <string>

class AbstractTicket {
public:
    // Pure virtual method
    virtual void abstractMethod() const = 0;
};