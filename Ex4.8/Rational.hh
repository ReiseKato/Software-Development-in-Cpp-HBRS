#ifndef RATIONAL_HH
#define RATIONAL_HH

#include <iostream>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class Rational
{
public:
    using Integer = int;
    using Natural = int;

private:
    Integer numerator_;
    Natural denominator_;

public:
    Rational()
        : numerator_{0}, denominator_{1} {}
    
    Rational(Integer num)
        : numerator_{num}, denominator_{1} {}
    
    Rational(int dividend, int divisor)
    {
        if (divisor == 0)
        {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        int common_divisor = gcd(dividend, divisor);
        numerator_ = dividend / common_divisor;
        denominator_ = divisor / common_divisor;
        if (denominator_ < 0)
        {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

    Integer numer() const
    {
        return numerator_;
    }

    Natural denom() const
    {
        return denominator_;
    }

    // Compund assignment operators
    Rational& operator+=(const Rational& other)
    {
        numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        denominator_ *= other.denominator_;
        int common_divisor = gcd(numerator_, denominator_);
        numerator_ /= common_divisor;
        denominator_ /= common_divisor;
        return *this;
    }

    Rational& operator-=(const Rational& other)
    {
        numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        denominator_ *= other.denominator_;
        int common_divisor = gcd(numerator_, denominator_);
        numerator_ /= common_divisor;
        denominator_ /= common_divisor;
        return *this;
    }

    Rational& operator*=(const Rational& other)
    {
        numerator_ *= other.numerator_;
        denominator_ *= other.denominator_;
        int common_divisor = gcd(numerator_, denominator_);
        numerator_ /= common_divisor;
        denominator_ /= common_divisor;
        return *this;
    }

    Rational& operator/=(const Rational& other)
    {
        if (other.numerator_ == 0)
        {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        numerator_ *= other.denominator_;
        denominator_ *= other.numerator_;
        int common_divisor = gcd(numerator_, denominator_);
        numerator_ /= common_divisor;
        denominator_ /= common_divisor;
        return *this;
    }

    // relational operators
    friend bool operator==(const Rational& lhs, const Rational& rhs)
    {
        return (lhs.numerator_ == rhs.numerator_) && (lhs.denominator_ == rhs.denominator_);
    }

    friend bool operator!=(const Rational& lhs, const Rational& rhs)
    {
        return !(lhs == rhs);
    }

    friend bool operator<(const Rational& lhs, const Rational& rhs)
    {
        return (lhs.numerator_ * rhs.denominator_) < (rhs.numerator_ * lhs.denominator_);
    }

    friend bool operator<=(const Rational& lhs, const Rational& rhs)
    {
        return (lhs < rhs) || (lhs == rhs);
    }

    friend bool operator>(const Rational& lhs, const Rational& rhs)
    {
        return !(lhs <= rhs);
    }

    friend bool operator>=(const Rational& lhs, const Rational& rhs)
    {
        return !(lhs < rhs);
    }

    // arithmetic operators
    friend Rational operator+(Rational lhs, const Rational& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    friend Rational operator-(Rational lhs, const Rational& rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    friend Rational operator*(Rational lhs, const Rational& rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    friend Rational operator/(Rational lhs, const Rational& rhs)
    {
        lhs /= rhs;
        return lhs;
    }

    // reciprocal
    Rational recip() const
    {
        if (numerator_ == 0)
        {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        return Rational(denominator_, numerator_);
    }

    void print()
    {
        std::cout << "Numerator: " << numerator_ << ", Denominator: " << denominator_ << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
    os << r.numer() << "/" << r.denom();
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r)
{
    int num, denom;
    char slash;
    is >> num >> slash >> denom;
    if (slash != '/' || denom == 0)
    {
        std::cerr << "Error: Invalid input format or division by zero." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    r = Rational(num, denom);
    return is;
}

class Vector2D
{
public:
    using Coord = Rational;

private:
    Coord x_;
    Coord y_;

public:
    Vector2D(Coord x = 0, Coord y = 0)
        : x_{x}, y_{y} {}
    
    void print() const
    {
        std::cout << "Vector2D(" << x_ << ", " << y_ << ")" << std::endl;
    }

    // friend Vector2D operator,(const Coord& x, const Coord& y)
    // {
    //     return Vector2D(x, y);
    // }

    Vector2D operator+=(Vector2D& other)
    {
        other.x_ += x_;
        other.y_ += y_;
        return *this;
    }
};







#endif // RATIONAL_HH