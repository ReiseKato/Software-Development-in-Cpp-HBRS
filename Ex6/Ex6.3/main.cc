#include <iostream>
#include "linalg/Vector2D.hh"
#include "linalg/Vector3D.hh"
#include "linalg/Complex.hh"
#include "linalg/Rational.hh"
#include "linalg/VectorUtil.hh"

int main()
{
    linalg::Vector2D v1(1.0, 2.0);
    linalg::Vector2D v2(3.0, 4.0);

    double norm_v1 = linalg::norm2(v1);

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << norm_v1 << std::endl;
    

    return 0;
}
