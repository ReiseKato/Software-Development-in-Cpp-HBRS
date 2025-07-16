#include <iostream>
#include "linalg/Vector2D.hh"
#include "linalg/Complex.hh"
#include "linalg/Rational.hh"

int main() {
    linalg::Vector2D v1;
    linalg::Vector2D v2;

    v1 = linalg::Vector2D(linalg::Rational(1, 2), linalg::Rational(3, 4));
    v2 = linalg::Vector2D(linalg::Rational(5, 6), linalg::Rational(7, 8));

    std::cout << "Vector 1: " << v1 << std::endl;
    


    return 0;
}
