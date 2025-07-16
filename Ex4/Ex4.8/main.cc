#include "Rational.hh"

int main()
{
    Vector2D::Coord x(1, 2); // Rational(1, 2)
    Vector2D::Coord y(3, 4); // Rational(3, 4)
    
    Vector2D v1;
    Vector2D v2(x, y); // Creates a Vector2D with x = Rational(1, 2), y = Rational(3, 4)
    Vector2D v3(x, y); // Alternative way to create a Vector2D

    v1 = Vector2D(x, y); // Creates a Vector2D with x = Rational(1, 2), y = Rational(3, 4)

    v1 += v2;
    
    v1.print();  // Outputs: Vector2D(1/2, 3/4)
    v2.print();
    v3.print();

    return 0;
}