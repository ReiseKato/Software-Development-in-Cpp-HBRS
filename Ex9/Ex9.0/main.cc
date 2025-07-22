#include <iostream>
#include <vector>
#include "linalg/VectorDyn.hh"

int main() {
    using namespace linalg;

    VectorDyn v1{ {1, 2}, {3, 4} };
    VectorDyn v2{ {5, 0}, {1, -2} };

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";

    auto v3 = v1 + v2;
    std::cout << "v1 + v2 = " << v3 << "\n";

    std::cout << "Dot product: " << (v1 * v2) << "\n";

    std::cout << "Norm^2 of v1: " << norm(v1) << "\n";

    return 0;
}
