#ifndef LINALG_VECTOR2D_HH
#define LINALG_VECTOR2D_HH

#include <iostream>
#include "Complex.hh"

namespace linalg
{

    class Vector2D {
    public:
        using Coord = Complex;

    private:
        Coord x_;
        Coord y_;

    public:
        Vector2D();
        Vector2D(Coord const& x, Coord const& y);

        Coord const& x() const;
        Coord const& y() const;

        Vector2D& operator+=(Vector2D const& v);
        Vector2D& operator-=(Vector2D const& other);
        Vector2D& operator*=(Coord const& scalar);
        Vector2D& operator/=(Coord const& scalar);

        // operator [] that takes an index (natural number) and returns the corresponding coordinate by reference
        Coord& operator[](std::size_t index);

        friend std::istream& operator>>(std::istream& is, Vector2D& v);
    };

    double norm2(Vector2D const& v);

    std::ostream& operator<<(std::ostream& os, Vector2D const& v);

    // binary operators
    Vector2D operator+(Vector2D const& a, Vector2D const& b);
    Vector2D operator-(Vector2D const& a, Vector2D const& b);
    Vector2D operator*(Vector2D const& v, Vector2D::Coord const& scalar);
    Vector2D operator*(Vector2D::Coord const& scalar, Vector2D const& v);
    Vector2D::Coord operator*(Vector2D const& v, Vector2D const& other);
    Vector2D operator/(Vector2D const& v, Vector2D::Coord const& scalar);
    bool operator==(Vector2D const& a, Vector2D const& b);

    // unary operator
    Vector2D operator-(Vector2D const& v);

    // barycentre
    void baryIO2D();

} // namespace linalg

#endif // LINALG_VECTOR2D_HH
