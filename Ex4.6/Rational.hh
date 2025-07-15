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

    Rational add(const Rational& other) const
    {
        Integer new_numerator = this->numerator_ * other.denominator_ + other.numerator_ * this->denominator_;
        Natural new_denominator = this->denominator_ * other.denominator_;
        return Rational(new_numerator, new_denominator);
    }

    void print()
    {
        std::cout << "Numerator: " << numerator_ << ", Denominator: " << denominator_ << std::endl;
    }
};


Rational operator+(const Rational& lhs, const Rational& rhs)
{
    return lhs.add(rhs);
}





#endif // RATIONAL_HH