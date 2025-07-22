#include "VectorDyn.hh"
#include <cmath>

namespace linalg
{
    VectorDyn::VectorDyn() : data_() {}

    VectorDyn::VectorDyn(size_t size) : data_(size) {}

    VectorDyn::VectorDyn(const std::initializer_list<Coord>& values_list) : data_{values_list} {}

    std::size_t VectorDyn::size() const
    {
        return data_.size();
    }

    const VectorDyn::Coord& VectorDyn::operator[](size_t index) const
    {
        return data_.at(index);
    }

    VectorDyn::Coord& VectorDyn::operator[](size_t index)
    {
        return data_.at(index);
    }

    VectorDyn VectorDyn::operator+=(const VectorDyn& other)
    {
        if (size() != other.size())
            throw std::length_error("Vectors must be of the same size for addition.");
        for (size_t i = 0; i < size(); ++i)
        {
            data_[i] += other[i];
        }
        return *this;
    }

    VectorDyn VectorDyn::operator-=(const VectorDyn& other)
    {
        if (size() != other.size())
            throw std::length_error("Vectors must be of the same size for subtraction.");
        for (size_t i = 0; i < size(); ++i)
        {
            data_[i] -= other[i];
        }
        return *this;
    }

    VectorDyn VectorDyn::operator*=(const Coord& scalar)
    {
        for (auto& coord : data_)
        {
            coord *= scalar;
        }
        return *this;
    }

    VectorDyn VectorDyn::operator*=(const VectorDyn& other)
    {
        if (size() != other.size())
            throw std::length_error("Vectors must be of the same size for multiplication.");
        for (size_t i = 0; i < size(); ++i)
        {
            data_[i] *= other[i];
        }
        return *this;
    }

    VectorDyn VectorDyn::operator/=(const Coord& scalar)
    {
        if (scalar == Coord(0.0, 0.0))
            throw std::invalid_argument("Division by zero is not allowed.");
        for (auto& coord : data_)
        {
            coord /= scalar;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const VectorDyn& vector)
    {
        os << "[";
        for (size_t i = 0; i < vector.size() - 1; ++i)
        {
            os << vector[i] << ", ";
        }
        os << vector[vector.size() - 1] << "]";
        return os;
    }

    std::istream& operator>>(std::istream& is, VectorDyn& vector)
    {
        char ch;
        is >> ch;  // Read the opening bracket
        if (ch != '[')
        {
            is.setstate(std::ios::failbit);
            return is;
        }

        VectorDyn::Coord coord;
        while (is >> coord)
        {
            vector.push_back(coord);
            is >> ch;  // Read the next character
            if (ch == ']')
                break;
            else if (ch != ',')
            {
                is.setstate(std::ios::failbit);
                return is;
            }
        }
        return is;
    }

    void VectorDyn::push_back(const Coord& value)
    {
        data_.push_back(value);
    }

    VectorDyn operator+(const VectorDyn& lhs, const VectorDyn& rhs)
    {
        VectorDyn result = lhs;
        result += rhs;
        return result;
    }

    VectorDyn operator-(const VectorDyn& lhs, const VectorDyn& rhs)
    {
        VectorDyn result = lhs;
        result -= rhs;
        return result;
    }

    VectorDyn operator*(const VectorDyn& lhs, const VectorDyn::Coord& scalar)
    {
        VectorDyn result = lhs;
        result *= scalar;
        return result;
    }

    VectorDyn operator*(const VectorDyn& lhs, const VectorDyn& rhs)
    {
        VectorDyn result = lhs;
        result *= rhs;
        return result;
    }

    VectorDyn operator/(const VectorDyn& lhs, const VectorDyn::Coord& scalar)
    {
        VectorDyn result = lhs;
        result /= scalar;
        return result;
    }

    VectorDyn operator-(const VectorDyn& vector)
    {
        VectorDyn result = vector;
        for (auto& coord : result.data_)
        {
            coord = -coord;  // Assuming Complex has a negation operator defined
        }
        return result;
    }

    double norm(const VectorDyn& vector)
    {
        double sum = 0.0;
        for (const auto& coord : vector.data_)
        {
            sum += coord.re() * coord.re() + coord.im() * coord.im();
        }
        return std::sqrt(sum);
    }

    bool operator==(const VectorDyn& lhs, const VectorDyn& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        for (size_t i = 0; i < lhs.size(); ++i)
        {
            if (lhs[i] != rhs[i])
                return false;
        }
        return true;
    }

    bool operator!=(const VectorDyn& lhs, const VectorDyn& rhs)
    {
        return !(lhs == rhs);
    }
}