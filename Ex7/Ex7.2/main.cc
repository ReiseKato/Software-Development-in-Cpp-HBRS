#include <iostream>
#include "linalg/Vector2D.hh"
#include "linalg/Vector3D.hh"
#include "linalg/Triangle.hh"
#include "linalg/Complex.hh"
#include "linalg/Rational.hh"
#include "linalg/VectorUtil.hh"

using ComplexBinaryOperator = linalg::Complex(*)(linalg::Complex const&, linalg::Complex const&);

int main()
{
    ComplexBinaryOperator operations[] = {
        linalg::operator+,
        linalg::operator-,
        linalg::operator*,
        linalg::operator/
    };

    linalg::Complex a(1.0, 2.0);
    linalg::Complex b(3.0, 4.0);

    for (const auto& op : operations) {
        linalg::Complex result = op(a, b);
        std::cout << "Result: " << result << std::endl;
    }


    return 0;
}
