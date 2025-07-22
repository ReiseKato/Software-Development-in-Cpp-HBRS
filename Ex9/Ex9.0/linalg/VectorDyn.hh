#ifndef VECOTR_DYN_HH
#define VECOTR_DYN_HH

#include <iostream>
#include <vector>
#include "Complex.hh"
#include "Rational.hh"

namespace linalg
{
    class VectorDyn
    {
        public:
            using Coord = Complex;
        
        private:
            std::vector<Coord> data_;

        public:
            VectorDyn();
            VectorDyn(size_t size);
            VectorDyn(const std::initializer_list<Coord>& values_list);

            // Accessors
            size_t size() const;
            const Coord& operator[](size_t index) const;
            Coord& operator[](size_t index);

            void push_back(const Coord& value);

            // Arithmetic operations
            VectorDyn operator+=(const VectorDyn& other);
            VectorDyn operator-=(const VectorDyn& other);
            VectorDyn operator*=(const Coord& scalar);
            VectorDyn operator*=(const VectorDyn& other);
            VectorDyn operator/=(const Coord& scalar);

            // Stream operators
            friend std::ostream& operator<<(std::ostream& os, const VectorDyn& vector);
            friend std::istream& operator>>(std::istream& is, VectorDyn& vector);

            friend VectorDyn operator-(const VectorDyn& vector);

            friend double norm(const VectorDyn& vector);
    };

    VectorDyn operator+(const VectorDyn& lhs, const VectorDyn& rhs);
    VectorDyn operator-(const VectorDyn& lhs, const VectorDyn& rhs);
    VectorDyn operator*(const VectorDyn& lhs, const VectorDyn::Coord& scalar);
    VectorDyn operator*(const VectorDyn& lhs, const VectorDyn& rhs);
    VectorDyn operator/(const VectorDyn& lhs, const VectorDyn::Coord& scalar);

    bool operator==(const VectorDyn& lhs, const VectorDyn& rhs);
    bool operator!=(const VectorDyn& lhs, const VectorDyn& rhs);
}


#endif // VECOTR_DYN_HH