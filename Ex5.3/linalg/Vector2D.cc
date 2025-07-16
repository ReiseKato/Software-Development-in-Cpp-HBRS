#include "Vector2D.hh"

namespace linalg {

std::ostream& operator<<(std::ostream& os, Vector2D const& v) {
    os << "(" << v.x() << "," << v.y() << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2D& v) {
    char c;
    is >> c;       // Read '('
    is >> v.x_;
    is >> c;       // Read ','
    is >> v.y_;
    is >> c;       // Read ')'
    return is;
}

// binary operators
Vector2D operator+(Vector2D const& a, Vector2D const& b)
{
    return Vector2D(a.x() + b.x(), a.y() + b.y());
}

Vector2D operator-(Vector2D const& a, Vector2D const& b)
{
    return Vector2D(a.x() - b.x(), a.y() - b.y());
}

Vector2D operator*(Vector2D const& v, Vector2D::Coord const& scalar)
{
    return Vector2D(v.x() * scalar, v.y() * scalar);
}

Vector2D operator*(Vector2D::Coord const& scalar, Vector2D const& v)
{
    return Vector2D(v.x() * scalar, v.y() * scalar);
}

Vector2D::Coord operator*(Vector2D const& v, Vector2D const& other)
{
    return v.x() * other.x() + v.y() * other.y();
}

Vector2D operator/(Vector2D const& v, Vector2D::Coord const& scalar)
{
    if (scalar == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return Vector2D(v.x() / scalar, v.y() / scalar);
}

// uniary operator
Vector2D operator-(Vector2D const& v)
{
    return Vector2D(-v.x(), -v.y());
}





} // namespace linalg
