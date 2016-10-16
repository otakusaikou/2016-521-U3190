#include <iostream>
#include <cstring>
#include <vector>
#include "Fraction.h"

//
// Compute the greatest common divisor of given two numbers a and b
//
int gcd(const int &a, const int &b)
{
    return b == 0 ? a : gcd(b, a % b);
}

//
// Compute the least common multiple of given two numbers a and b
//
int lcm(const int &a, const int &b)
{
    int gcd_ab = gcd(a, b);
    return gcd_ab ? (a / gcd_ab * b) : 0;
}

//
// Reduce the given fraction
//
void reduce(Fraction &f)
{
    // Find the greatest common divisor of numerator and denominator
    int gcd_nd;
    gcd_nd = gcd(f.num, f.den);
    f.num /= gcd_nd;
    f.den /= gcd_nd;
}

//
// Summerize the vector of fraction
//
Fraction sum_frac(std::vector<Fraction> &vf)
{
    // Find the greatest common divisor of all denominators
    int gcd_den = vf.at(0).den;
    for (auto &e : vf) {
        gcd_den = gcd(gcd_den, e.den);
    }

    // Find the least common multiple of all denominators
    int lcm_den = vf.at(0).den;
    int prod_den = 1;               // Product of denominators
    for (auto &e : vf) {
        prod_den *= e.den;
        lcm_den = lcm(lcm_den, e.den);
    }

    // Reduce each fraction if the product and the least common multiple
    // of all denominators are not equal
    if (prod_den != lcm_den) {
        std::cout << "After reduce: ";
        for (auto &e : vf) {
            reduce(e);
            std::cout << e.num << "/" << e.den << " ";
        }
        // Update the least common multiple
        lcm_den = vf.at(0).den;
        for (auto &e : vf) {
            lcm_den = lcm(lcm_den, e.den);
        }
        std::cout << std::endl;
    }

    // Compute the numerator after summation of all the fractions
    int ans_num = 0;
    for (auto &e : vf) {
        ans_num += e.num * (lcm_den / e.den);
    }

    Fraction sum;
    sum.num = ans_num;
    sum.den = lcm_den;
    return sum;
}

int main()
{
    // User input for part1
    std::vector<Fraction> vf;
    Fraction f;
    std::cout << "(1)Enter some fractions terminated by '#'" << std::endl;

    // Read the fractions and put them into the vector
    while (std::cin >> f) {
        vf.push_back(f);
    }

    // Summerize the fractions and output the result
    Fraction sum = sum_frac(vf);
    std::cout << "The summation of these fractions: "
        << sum.num << "/" << sum.den << std::endl
    << std::endl;

    // User input for part2
    vf.clear();
    std::cout << "(2)Enter some fractions terminated by '#'" << std::endl;

    // Reset the input state
    std::cin.clear();
    std::cin.ignore();

    // Read the fractions and put them into the vector
    while (std::cin >> f) {
        vf.push_back(f);
    }

    // Summerize the fractions and output the result
    sum = sum_frac(vf);
    std::cout << "The summation of there fractions: "
        << sum.num << "/" << sum.den << std::endl;

    // Reduce the summation
    reduce(sum);
    std::cout << "The summation after reduce: "
        << sum.num << "/" << sum.den << std::endl;
    return 0;
}
