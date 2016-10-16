#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

struct Fraction
{
    int num;        // numerator
    int den;        // denominator
};

std::istream &operator >> (std::istream &in, Fraction &f)
{
    in >> f.num;
    in.ignore();
    in >> f.den;
    // check that the inputs succeeded
    if (!in) {
        f = Fraction();  // Input failed, reset object to default state
    }
    return in;
}

#endif
