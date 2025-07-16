#include "Vector3D.hh"
#include <iostream>

namespace linalg
{
    Vector3D::Vector3D()
        : Vector3D{0, 0, 0} {std::cout << "Vector3D this:" << this << " &x:" << &x_ << " &y:" << &y_ << " &z:" << &z_ << std::endl;}
    
    Vector3D::Vector3D(Coord const& x, Coord const& y, Coord const& z)
        : x_{x}, y_{y}, z_{z} {std::cout << "Vector3D this:" << this << " &x:" << &x_ << " &y:" << &y_ << " &z:" << &z_ << std::endl;}
    
    Vector3D::Coord const& Vector3D::x() const
    {
        return x_;
    }

    Vector3D::Coord const& Vector3D::y() const
    {
        return y_;
    }

    Vector3D::Coord const& Vector3D::z() const
    {
        return z_;
    }

    Vector3D& Vector3D::operator+=(Vector3D const& v)
    {
        x_ += v.x();
        y_ += v.y();
        z_ += v.z();

        return *this;
    }

    Vector3D& Vector3D::operator-=(Vector3D const& other)
    {
        x_ -= other.x();
        y_ -= other.y();
        z_ -= other.z();

        return *this;
    }

    Vector3D& Vector3D::operator*=(Coord const& scalar)
    {
        x_ *= scalar;
        y_ *= scalar;
        z_ *= scalar;

        return *this;
    }

    Vector3D& Vector3D::operator/=(Coord const& scalar)
    {
        if (scalar.numer() == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        x_ /= scalar;
        y_ /= scalar;
        z_ /= scalar;

        return *this;
    }

    Vector3D::Coord& Vector3D::operator[](std::size_t index)
    {
        if (index == 0) return x_;
        if (index == 1) return y_;
        if (index == 2) return z_;
        throw std::out_of_range("Index out of range for Vector3D");
    }

    std::istream& operator>>(std::istream& is, Vector3D& v)
    {
        Vector3D::Coord x, y, z;
        char comma1, comma2;
        is >> x >> comma1 >> y >> comma2 >> z;
        if (comma1 != ',' || comma2 != ',') {
            std::cerr << "Error: Invalid input format." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        v = Vector3D(x, y, z);
        return is;
    }

    std::ostream& operator<<(std::ostream& os, Vector3D const& v)
    {
        os << "Vector3D(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
        return os;
    }

    Vector3D operator+(Vector3D const& a, Vector3D const& b)
    {
        Vector3D result = a;
        result += b;
        return result;
    }

    Vector3D operator-(Vector3D const& a, Vector3D const& b)
    {
        Vector3D result = a;
        result -= b;
        return result;
    }

    Vector3D operator*(Vector3D const& v, Vector3D::Coord const& scalar)
    {
        Vector3D result = v;
        result *= scalar;
        return result;
    }

    Vector3D operator*(Vector3D::Coord const& scalar, Vector3D const& v)
    {
        return v * scalar; // Reuse the multiplication operator
    }

    Vector3D::Coord operator*(Vector3D const& v, Vector3D const& other)
    {
        Vector3D::Coord result = v.x() * other.x() + v.y() * other.y() + v.z() * other.z(); // Scalar product
        return result;
    }

    Vector3D operator/(Vector3D const& v, Vector3D::Coord const& scalar)
    {
        if (scalar.numer() == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        Vector3D result = v;
        result /= scalar;
        return result;
    }

    Vector3D operator-(Vector3D const& v)
    {
        return Vector3D(-v.x(), -v.y(), -v.z());
    }

    void baryIO3D()
    {
        Vector3D input;
        Vector3D sum;
        int count = 0;
        std::cout << "Enter a vector in the form (x,y): ";
        while(std::cin >> input)
        {
            sum += input;
            ++count;

            Vector3D barycentre = sum / static_cast<Vector3D::Coord>(count);

            std::cout << "Barycentre so far: " << barycentre << std::endl;
            if (std::cin.eof() == true) {
                break;
            }
            std::cout << "Enter a vector in the form (x,y): ";
        }
    }
} // namespace linalg