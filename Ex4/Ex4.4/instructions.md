1. In a header file `Rational.hh` provide:
    - global function `gcd` that takes two `int`-values and returns their positive GCD - using Euclid's algorithm on the absolute values of the numbers
    - class `Rational` that models rational numbers, providing:
        - type `Integer`, used to represent the numerator
        - type `Natural`, used to represent the denominator (you may choose it as int)
        - a default constructor (number becomes 0)
        - a constructor taking one argument (as numerator; the denominator is 1)
        - a constructor that takes two int arguments (dividend and divisor) and creates the fraction as their quotient in reduced form – reducing both by their greatest common divisor (GCD) and making the denominator non-negative

For testing, provide temporarily a member function print that writes numerator and denominator to std::cout.  (We will see a cleaner solution in short time.)

In a separate source file, #include the header and provide a test function main.