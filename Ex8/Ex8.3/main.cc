#include <iostream>
#include "linalg/Triangle.hh"
#include "linalg/Vector2D.hh"

using namespace linalg;

int main() {
    // Create some shared vertices (Vector2D objects)
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

    // Create an array of triangle pointers
    const Triangle<Vector2D>* triangleArray[4] = { &t1, &t2, &t3, &t4 };

    // Call isPatch
    bool result = isPatch(triangleArray, 4);

    std::cout << "Is connected patch? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
