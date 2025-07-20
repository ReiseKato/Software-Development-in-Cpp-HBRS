#include "Vector2D.hh"
#include <cmath>

namespace linalg {

    Vector2D::Vector2D()
        : Vector2D{0, 0} {std::cout << "this:" << this << " &x:" << &x_ << " &y:" << &y_ << std::endl;}

    Vector2D::Vector2D(Coord const& x, Coord const& y)
        : x_{x}, y_{y} {std::cout << "Vector2D this:" << this << " &x:" << &x_ << " &y:" << &y_ << std::endl;}

    Vector2D::Coord const& Vector2D::x() const { return x_; }
    Vector2D::Coord const& Vector2D::y() const { return y_; }

    Vector2D& Vector2D::operator+=(Vector2D const& v) {
        x_ += v.x_;
        y_ += v.y_;
        return *this;
    }

    Vector2D& Vector2D::operator-=(Vector2D const& other)
    {
        x_ -= other.x_;
        y_ -= other.y_;
        return *this;
    }

    Vector2D& Vector2D::operator*=(Coord const& scalar) {
        x_ *= scalar;
        y_ *= scalar;
        return *this;
    }

    Vector2D& Vector2D::operator/=(Coord const& scalar) {
        if (scalar == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        x_ /= scalar;
        y_ /= scalar;
        return *this;
    }

    // operator [] that takes an index (natural number) and returns the corresponding coordinate by reference
    Vector2D::Coord& Vector2D::operator[](std::size_t index) {
        if (index == 0) return x_;
        if (index == 1) return y_;
        throw std::out_of_range("Index out of range for Vector2D");
    }

    double norm2(Vector2D const& v)
    {
        Vector2D::Coord x_conj = v.x().conjugate();
        Vector2D::Coord y_conj = v.y().conjugate();
        return std::sqrt(x_conj * v.x() + y_conj * v.y());
    }

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

    void baryIO2D()
    {
        Vector2D input;
        Vector2D sum;
        int count = 0;
        std::cout << "Enter a vector in the form (x,y): ";
        while(std::cin >> input)
        {
            sum += input;
            ++count;

            Vector2D barycentre = sum / static_cast<Vector2D::Coord>(count);

            std::cout << "Barycentre so far: " << barycentre << std::endl;
            if (std::cin.eof() == true) {
                break;
            }
            std::cout << "Enter a vector in the form (x,y): ";
        }
    }




} // namespace linalg
