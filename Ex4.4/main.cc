#include "Rational.hh"

int main()
{
    Rational r1; // Default constructor
    Rational r2(3); // Constructor with one integer
    Rational r3(6, 8); // Constructor with two integers
    Rational r4(5, -10); // Negative denominator
    Rational r5(-3, -9); // Both numerator and denominator negative
    Rational r6(0, 1); // Zero numerator
    r1.print();
    r2.print();
    r3.print();
    r4.print();
    r5.print();
    r6.print();
    return 0;
}