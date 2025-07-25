#ifndef LINALG_COMPLEX_HH
#define LINALG_COMPLEX_HH

#include <iostream>
#include <cmath>

namespace linalg
{
    class Complex
    {
    public:
        using Real = double;

    private:
        Real real_;
        Real imaginary_;

    public:
        Complex();
        Complex(Real real);
        Complex(Real real, Real imaginary);
        
        Real re() const;
        Real im() const;

        Complex division(const Complex& other) const;

        // arithmetic assignment operators
        Complex& operator+=(const Complex& other);
        Complex& operator-=(const Complex& other);
        Complex& operator*=(const Complex& other);
        Complex& operator/=(const Complex& other);

        // conjugate
        Complex conjugate() const;

        // cast operators
        operator double() const;
    };

    Complex operator+(const Complex& lhs, const Complex& rhs);
    Complex operator-(const Complex& lhs, const Complex& rhs);
    Complex operator*(const Complex& lhs, const Complex& rhs);
    Complex operator/(const Complex& lhs, const Complex& rhs);
    
    bool operator==(const Complex& lhs, const Complex& rhs);
    bool operator==(const Complex& lhs, const int rhs);
    bool operator==(const int lhs, const Complex& rhs);

    Complex operator-(const Complex& c);

    std::ostream& operator<<(std::ostream& os, const Complex& c);
    std::istream& operator>>(std::istream& is, Complex& c);
}

#endif // LINALG_COMPLEX_HH