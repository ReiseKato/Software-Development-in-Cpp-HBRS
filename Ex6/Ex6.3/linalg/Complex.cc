#include "Complex.hh"
#include <iostream>

namespace linalg
{
    Complex::Complex()
        : real_{0.0}, imaginary_{0.0} {}
    Complex::Complex(Real real)
        : real_{real}, imaginary_{0.0} {}
    Complex::Complex(Real real, Real imaginary)
        : real_{real}, imaginary_{imaginary} {}
    
    Complex::Real Complex::re() const
    {
        return real_;
    }

    Complex::Real Complex::im() const
    {
        return imaginary_;
    }

    Complex Complex::division(const Complex& other) const
    {
        Real denominator = other.re() * other.re() + other.im() * other.im();
        if (denominator == 0.0)
        {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        return Complex((real_ * other.re() + imaginary_ * other.im()) / denominator,
                    (imaginary_ * other.re() - real_ * other.im()) / denominator);
    }

    // arithmetic assignment operators
    Complex& Complex::operator+=(const Complex& other)
    {
        real_ += other.re();
        imaginary_ += other.im();
        return *this;
    }

    Complex& Complex::operator-=(const Complex& other)
    {
        real_ -= other.re();
        imaginary_ -= other.im();
        return *this;
    }

    Complex& Complex::operator*=(const Complex& other)
    {
        Real new_real = real_ * other.re() - imaginary_ * other.im();
        Real new_imaginary = real_ * other.im() + imaginary_ * other.re();
        real_ = new_real;
        imaginary_ = new_imaginary;
        return *this;
    }

    Complex& Complex::operator/=(const Complex& other)
    {
        *this = this->division(other);
        return *this;
    }

    // conjugate
    Complex Complex::conjugate() const
    {
        return Complex(real_, -imaginary_);
    }

    Complex::operator double() const
    {
        return std::sqrt(real_ * real_ + imaginary_ * imaginary_);
    }

    Complex operator+(const Complex& lhs, const Complex& rhs)
    {
        return Complex(lhs.re() + rhs.re(), lhs.im() + rhs.im());
    }

    Complex operator-(const Complex& lhs, const Complex& rhs)
    {
        return Complex(lhs.re() - rhs.re(), lhs.im() - rhs.im());
    }

    Complex operator*(const Complex& lhs, const Complex& rhs)
    {
        return Complex(lhs.re() * rhs.re() - lhs.im() * rhs.im(),
                    lhs.re() * rhs.im() + lhs.im() * rhs.re());
    }

    Complex operator/(const Complex& lhs, const Complex& rhs)
    {
        return lhs.division(rhs);
    }

    bool operator==(const Complex& lhs, const Complex& rhs)
    {
        return (lhs.re() == rhs.re() && lhs.im() == rhs.im());
    }

    bool operator==(const Complex& lhs, const int rhs)
    {
        return (lhs.re() == static_cast<Complex::Real>(rhs) && lhs.im() == 0.0);
    }

    bool operator==(const int lhs, const Complex& rhs)
    {
        return (static_cast<Complex::Real>(lhs) == rhs.re() && rhs.im() == 0.0);
    }

    Complex operator-(const Complex& c)
    {
        return Complex(-c.re(), -c.im());
    }

    std::ostream& operator<<(std::ostream& os, const Complex& c)
    {
        os << c.re() << " + " << c.im() << "i";
        return os;
    }

    std::istream& operator>>(std::istream& is, Complex& c)
    {
        double real, imaginary;
        char plus, i;
        is >> real >> plus >> imaginary >> i;
        if (plus != '+' || i != 'i')
        {
            std::cerr << "Error: Invalid input format for Complex number." << std::endl;
            is.setstate(std::ios::failbit);
            return is;
        }
        c = Complex(real, imaginary);
        return is;
    }
} // namespace linalg

