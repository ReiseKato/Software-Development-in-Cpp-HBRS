#include <iostream>
#include "linalg/Vector2D.hh"
#include "linalg/Vector3D.hh"
#include "linalg/Triangle.hh"
#include "linalg/Complex.hh"
#include "linalg/Rational.hh"
#include "linalg/VectorUtil.hh"

int main()
{
    linalg::Complex v1_c1(1.0, 2.0);
    linalg::Complex v1_c2(3.0, 4.0);
    linalg::Complex v2_c1(5.0, 6.0);
    linalg::Complex v2_c2(7.0, 8.0);
    linalg::Complex v3_c1(9.0, 10.0);
    linalg::Complex v3_c2(11.0, 12.0);
    
    linalg::Vector2D v1(v1_c1, v1_c2);
    linalg::Vector2D v2(v2_c1, v2_c2);
    linalg::Vector2D v3(v3_c1, v3_c2);

    linalg::Vector2D* ptr_v1 = &v1;
    linalg::Vector2D* ptr_v2 = &v2;
    linalg::Vector2D* ptr_v3 = &v3;

    linalg::Triangle<linalg::Vector2D> triangle1(ptr_v1, ptr_v2, ptr_v3);
    linalg::Triangle<linalg::Vector2D> triangle2(ptr_v1, ptr_v2, ptr_v3);

    bool areEqual = linalg::isEqual(triangle1, triangle2);

    std::cout << areEqual << std::endl;

    return 0;
}
