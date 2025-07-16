#include "Rational.hh"

namespace linalg
{
    Rational::Rational()
        : numerator_{0}, denominator_{1} {}
    
    Rational::Rational(Integer num)
        : numerator_{num}, denominator_{1} {}
    
    Rational::Rational(int dividend, int divisor)
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

    Rational::Integer Rational::numer() const
    {
        return numerator_;
    }

    Rational::Natural Rational::denom() const
    {
        return denominator_;
    }

    // Compund assignment operators
    Rational& Rational::operator+=(const Rational& other)
    {
        numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        denominator_ *= other.denominator_;
        int common_divisor = gcd(numerator_, denominator_);
        numerator_ /= common_divisor;
        denominator_ /= common_divisor;
        return *this;
    }

    Rational& Rational::operator-=(const Rational& other)
    {
        numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        denominator_ *= other.denominator_;
        int common_divisor = gcd(numerator_, denominator_);
        numerator_ /= common_divisor;
        denominator_ /= common_divisor;
        return *this;
    }

    Rational& Rational::operator*=(const Rational& other)
    {
        numerator_ *= other.numerator_;
        denominator_ *= other.denominator_;
        int common_divisor = gcd(numerator_, denominator_);
        numerator_ /= common_divisor;
        denominator_ /= common_divisor;
        return *this;
    }

    Rational& Rational::operator/=(const Rational& other)
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

    // reciprocal
    Rational Rational::recip() const
    {
        if (numerator_ == 0)
        {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        return Rational(denominator_, numerator_);
    }

    // Rational class implementation
    void Rational::print()
    {
        std::cout << "Numerator: " << numerator_ << ", Denominator: " << denominator_ << std::endl;
    }





    // Overloaded stream operators

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

    // relational operators
    bool operator==(const Rational& lhs, const Rational& rhs)
    {
        return (lhs.numer() == rhs.numer()) && (lhs.denom() == rhs.denom());
    }
    bool operator!=(const Rational& lhs, const Rational& rhs)
    {
        return !(lhs == rhs);
    }
    bool operator<(const Rational& lhs, const Rational& rhs)
    {
        return (lhs.numer() * rhs.denom()) < (rhs.numer() * lhs.denom());
    }
    bool operator<=(const Rational& lhs, const Rational& rhs)
    {
        return (lhs < rhs) || (lhs == rhs);
    }
    bool operator>(const Rational& lhs, const Rational& rhs)
    {
        return !(lhs <= rhs);
    }
    bool operator>=(const Rational& lhs, const Rational& rhs)
    {
        return !(lhs < rhs);
    }

    // arithmetic operators
    Rational operator+(Rational lhs, const Rational& rhs)
    {
        lhs += rhs;
        return lhs;
    }
    Rational operator-(Rational lhs, const Rational& rhs)
    {
        lhs -= rhs;
        return lhs;
    }
    Rational operator*(Rational lhs, const Rational& rhs)
    {
        lhs *= rhs;
        return lhs;
    }
    Rational operator/(Rational lhs, const Rational& rhs)
    {
        lhs /= rhs;
        return lhs;
    }
}