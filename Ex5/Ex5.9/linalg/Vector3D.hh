#ifndef VECTOR3D_HH
#define VECTOR3D_HH

#include "Rational.hh"

namespace linalg
{
    class Vector3D
    {
        public:
            using Coord = Rational;
        
        private:
            Coord x_;
            Coord y_;
            Coord z_;
        
        public:
            Vector3D();
            Vector3D(Coord const& x, Coord const& y, Coord const& z);
            Coord const& x() const;
            Coord const& y() const;
            Coord const& z() const;

            Vector3D& operator+=(Vector3D const& v);
            Vector3D& operator-=(Vector3D const& other);
            Vector3D& operator*=(Coord const& scalar);
            Vector3D& operator/=(Coord const& scalar);

            Coord& operator[](std::size_t index);

            friend std::istream& operator>>(std::istream& is, Vector3D& v);
    };

    std::ostream& operator<<(std::ostream& os, Vector3D const& v);

    // binary operators
    Vector3D operator+(Vector3D const& a, Vector3D const& b);
    Vector3D operator-(Vector3D const& a, Vector3D const& b);
    Vector3D operator*(Vector3D const& v, Vector3D::Coord const& scalar);
    Vector3D operator*(Vector3D::Coord const& scalar, Vector3D const& v);
    Vector3D::Coord operator*(Vector3D const& v, Vector3D const& other);
    Vector3D operator/(Vector3D const& v, Vector3D::Coord const& scalar);

    // unary operator
    Vector3D operator-(Vector3D const& v);

    // barycentre
    void baryIO3D();
} // namespace linalg







#endif // VECTOR3D_HH