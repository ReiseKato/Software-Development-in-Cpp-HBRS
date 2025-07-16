#include "Rational.hh"
#include <iostream>

int main() {
    Rational a(1, 2);
    Rational b(3, 4);

    std::cout << "a = " << a << ", b = " << b << '\n';
    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a - b = " << a - b << '\n';
    std::cout << "a * b = " << a * b << '\n';
    std::cout << "a / b = " << a / b << '\n';

    a += b;
    std::cout << "After a += b, a = " << a << '\n';

    std::cout << "Reciprocal of a: " << a.recip() << '\n';

    std::cout << std::boolalpha;
    std::cout << "a == b? " << (a == b) << '\n';
    std::cout << "a < b? " << (a < b) << '\n';
}
