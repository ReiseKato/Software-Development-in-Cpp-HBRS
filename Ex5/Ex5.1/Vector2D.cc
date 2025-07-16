#include <iostream>
#include "Vector2D.hh"

Vector2D::Vector2D() : x_{0}, y_{0} {}
Vector2D::Vector2D(int x, int y) : x_{x}, y_{y} {}

void Vector2D::print() const
{
    std::cout << "(" << x_ << ", " << y_ << ")\n";
}
