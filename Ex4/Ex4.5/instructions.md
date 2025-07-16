Extend Rational by:
- member functions numer and denom returning the respective values
- relational operators equal, less, greater, less/equal, greater/equal
- arithmetic operators negation, addition, subtraction, multiplication, division
- compound assignment operators (e.g., +=), which modify *this
- function recip returning the reciprocal (multiplicative inverse) of the number
- output and input operator for the format "n/d"

Where possible, use global rather than member functions – grant private access only if necessary.

Where appropriate, pass arguments by reference rather than by value.

Where applicable, make arguments read-only.