#pragma once
#include <iostream>

class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();                            // default constructor
    ~Fixed();                           // destructor
    Fixed(const Fixed &src);            // copy constructor
    Fixed &operator=(Fixed const &rhs); // copy assignation operator

    int getRawBits(void) const;
        // returns the raw value of the fixed point value
    void setRawBits(int const raw);
        // sets the raw value of the fixed-point number
};
