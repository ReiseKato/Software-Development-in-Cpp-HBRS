#ifndef LINALG_RATIONAL_HH
#define LINALG_RATIONAL_HH

#include <iostream>

namespace linalg
{

    int gcd(int a, int b);

    class Rational
    {
    public:
        using Integer = int;
        using Natural = int;

    private:
        Integer numerator_;
        Natural denominator_;

    public:
        Rational();
        
        Rational(Integer num);
        
        Rational(int dividend, int divisor);

        Integer numer() const;

        Natural denom() const;

        // Compund assignment operators
        Rational& operator+=(const Rational& other);
        Rational& operator-=(const Rational& other);
        Rational& operator*=(const Rational& other);
        Rational& operator/=(const Rational& other);

        // reciprocal
        Rational recip() const;

        void print();
    };

    std::ostream& operator<<(std::ostream& os, const Rational& r);

    std::istream& operator>>(std::istream& is, Rational& r);

    // relational operators
    bool operator==(const Rational& lhs, const Rational& rhs);
    bool operator!=(const Rational& lhs, const Rational& rhs);
    bool operator<(const Rational& lhs, const Rational& rhs);
    bool operator<=(const Rational& lhs, const Rational& rhs);
    bool operator>(const Rational& lhs, const Rational& rhs);
    bool operator>=(const Rational& lhs, const Rational& rhs);

    // arithmetic operators
    Rational operator+(Rational lhs, const Rational& rhs);
    Rational operator-(Rational lhs, const Rational& rhs);
    Rational operator*(Rational lhs, const Rational& rhs);
    Rational operator/(Rational lhs, const Rational& rhs);

    // unary operator
    Rational operator-(const Rational& r);

} // namespace linalg

#endif // LINALG_RATIONAL_HH