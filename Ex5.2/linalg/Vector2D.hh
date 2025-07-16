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

    friend std::istream& operator>>(std::istream& is, Vector2D& v);
};

std::ostream& operator<<(std::ostream& os, Vector2D const& v);

} // namespace linalg

#endif // LINALG_VECTOR2D_HH
