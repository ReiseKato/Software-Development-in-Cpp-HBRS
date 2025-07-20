#include <iostream>

using Type = unsigned int;

constexpr size_t BIT_COUNT = sizeof(Type) * 8;

// Functions for output and input
void bitOut(std::ostream &os, Type x)
{
    for (size_t i = BIT_COUNT - 1; i >= 0; --i)
    {
        os << ((x >> i) & 1);
        if (i == 0) break; // Prevents underflow, since size_t is unsigned
    }
    os << std::endl; // Add a newline for better readability
}

void bitIn(std::istream &is, Type &x)
{
    x = 0;
    std::string bits;
    is >> bits;
    for ( char bit : bits)
    {
        x = (x << 1);
        if (bit == '1')
        {
            x = (x | 1); // Set the least significant bit to 1
        }
        else if (bit != '0')
        {
            throw std::invalid_argument("Invalid bit input");
        }
    }
}

// Functions fo bit manipulation
bool get(Type x, size_t i)
{
    if (i >= BIT_COUNT)
    {
        throw std::out_of_range("Index out of range");
    }
    return ((x >> i) & 1);
}

// sets the i-th bit of x to value
Type set(Type x, size_t i, bool bit)
{
    if (i >= BIT_COUNT)
    {
        throw std::out_of_range("Index out of range");
    }
    if (bit)
    {
        x = x | (Type(1) << i);
    }
    else
    {
        x = x & ~(Type(1) << i);
    }
    return x;
}

// inserts a bit at index i in x, shifting the bits to the left
Type insL(Type x, size_t i, bool bit)
{
    if (i >= BIT_COUNT)
    {
        throw std::out_of_range("Index out of range");
    }

    Type left = x >> i; // Get the left part
    size_t rightShift = BIT_COUNT - i;
    Type right = x << rightShift; // Get the right part
    left = left << 1; // Shift left to make room for the new bit
    left = set(left, 0, bit); // Set the least significant bit to the new bit value
    left = left << i; // Shift left to the original position
    right = right >> rightShift; // Shift right to restore the original position
    return left | right; // Combine the two parts
}

Type insR(Type x, size_t i, bool bit)
{
    Type left = x >> i; // Get the left part
    Type right = x << (BIT_COUNT - i); // Get the right part
    right = right >> 1;
    right = set(right, BIT_COUNT - 1, bit);
    left = left << i; // Shift left to the original position
    right = right >> (BIT_COUNT - i); // Shift right to restore the original position
    return left | right; // Combine the two parts
}

Type delL(Type x, size_t i, bool fill_bit = false)
{
    if (i >= BIT_COUNT)
    {
        throw std::out_of_range("Index out of range");
    }

    Type left = x >> i + 1; // Get the left part
    Type right = x << (BIT_COUNT - i); // Get the right part
    left = left << i; // Shift left to the original position
    right = right >> (BIT_COUNT - i);
    return left | right; // Combine the two parts
}

Type delR(Type x, size_t i, bool fill_bit = false)
{
    if (i >= BIT_COUNT)
    {
        throw std::out_of_range("Index out of range");
    }

    Type left = x >> i; // Get the left part
    Type right = x << (BIT_COUNT - i + 1); // Get the right part
    right = right >> (BIT_COUNT - i); // Shift right to restore the original position
    left = left << i; // Shift left to the original position
    return left | right; // Combine the two parts
}



int main()
{
    Type x = 5; // 0000 0101
    Type y;
    // bitOut(std::cout, x);
    // bitIn(std::cin, x);
    // bitOut(std::cout, x);
    // bool bitValue = get(x, 2); // Get the value of the 2nd bit
    // std::cout << "Bit at index 2: " << bitValue << std::endl;
    // x = 42;
    // y = set(x, 1, true); // Set the 1st bit to 1
    // bitOut(std::cout, y);
    // y = insL(x, 4, true);
    // bitOut(std::cout, y);
    // y = insR(x, 4, true);
    // bitOut(std::cout, y);
    x = 42; // 0010 1010
    bitOut(std::cout, x);
    y = delL(x, 2);
    bitOut(std::cout, y);
    y = delR(x, 2);
    bitOut(std::cout, y);

    
    return 0;
}