#ifndef LINALG_VECTOR2D_HH
#define LINALG_VECTOR2D_HH

#include <iostream>

namespace linalg {

class Vector2D {
public:
    using Coord = double;

private:
    Coord x_;
    Coord y_;

public:
    Vector2D()
        : Vector2D{0, 0} {}

    Vector2D(Coord const& x, Coord const& y)
        : x_{x}, y_{y} {}

    Coord const& x() const { return x_; }
    Coord const& y() const { return y_; }

    Vector2D& operator+=(Vector2D const& v) {
        x_ += v.x_;
        y_ += v.y_;
        return *this;
    }

    Vector2D& operator-=(Vector2D const& other)
    {
        x_ -= other.x_;
        y_ -= other.y_;
        return *this;
    }

    Vector2D operator*=(Coord const& scalar) {
        x_ *= scalar;
        y_ *= scalar;
        return *this;
    }

    Vector2D& operator/=(Coord const& scalar) {
        if (scalar == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        x_ /= scalar;
        y_ /= scalar;
        return *this;
    }

    // operator [] that takes an index (natural number) and returns the corresponding coordinate by reference
    Coord& operator[](std::size_t index) {
        if (index == 0) return x_;
        if (index == 1) return y_;
        throw std::out_of_range("Index out of range for Vector2D");
    }


    friend std::istream& operator>>(std::istream& is, Vector2D& v);
};

std::ostream& operator<<(std::ostream& os, Vector2D const& v);

// binary operators
Vector2D operator+(Vector2D const& a, Vector2D const& b);
Vector2D operator-(Vector2D const& a, Vector2D const& b);
Vector2D operator*(Vector2D const& v, Vector2D::Coord const& scalar);
Vector2D operator*(Vector2D::Coord const& scalar, Vector2D const& v);
Vector2D::Coord operator*(Vector2D const& v, Vector2D const& other);
Vector2D operator/(Vector2D const& v, Vector2D::Coord const& scalar);

// unary operator
Vector2D operator-(Vector2D const& v);

} // namespace linalg

#endif // LINALG_VECTOR2D_HH
