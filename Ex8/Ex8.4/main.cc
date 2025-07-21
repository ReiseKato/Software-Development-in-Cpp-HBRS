#include <iostream>
#include <vector>
#include "linalg/Triangle.hh"
#include "linalg/Vector2D.hh"

int main() {
    using namespace linalg;

    Vector2D a(0, 0), b(1, 0), c(0, 1);
    Vector2D d(1, 1);
    Vector2D e(2, 0);
    Vector2D f(0, 2);
    Vector2D g(1, 2);
    Vector2D h(2, 1);

    // Construct triangles using pointers to shared vertices
    Triangle<Vector2D> t1(&a, &b, &c);
    Triangle<Vector2D> t2(&b, &d, &c);  // Shares edge (b, c) with t1
    Triangle<Vector2D> t3(&b, &e, &d);  // Shares edge (b, d) with t2
    Triangle<Vector2D> t4(&f, &g, &h);  // Disconnected triangle

    // Group pointers in vector
    std::vector<Triangle<Vector2D>*> triangles = { &t1, &t2, &t3};

    // Call isPatch
    bool result = isPatch(triangles);

    // Output result
    std::cout << "Triangles form a patch? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
