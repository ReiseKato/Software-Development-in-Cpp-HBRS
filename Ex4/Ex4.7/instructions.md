Write a class Complex, similar to Rational, that models complex numbers, providing:
- type Real, used to represent both the real and the imaginary part
- default constructor (number becomes 0)
- constructor taking one argument (real part; imaginary part is 0)
- constructor taking two arguments (real and imaginary part)
- functions re and im returning real and imaginary part of the number
- arithmetic operators negation, addition, subtraction, multiplication, division
- arithmetic assignment operators (e.g., +=), which modify *this
- function conj returning the complex conjugate of the number
- output and input operators for the format "re˘im i", e.g. 3-2i

Where possible, use global rather than member functions – grant private access only if necessary.

Where appropriate, pass arguments by reference rather than by value.

Where applicable, make arguments read-only.
