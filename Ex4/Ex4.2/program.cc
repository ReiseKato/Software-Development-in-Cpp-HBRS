#include <iostream>

int main()
{
    int a, b;

    std::cin >> a;
    std::cin >> b;

    std::cout << "Sum: " << (a + b) << std::endl;
    std::cout << "Diff: " << (a - b) << std::endl;
    std::cout << "Product: " << (a * b) << std::endl;
    std::cout << "Quotient: " << (a / b) << std::endl;
    std::cout << "Modulo: " << (a % b) << std::endl;
    std::cout << "Bitwise shift --> shift bits of a left by b bits: " << ( a << b) << std::endl;
    std::cout << "Arithmetic shift --> shift bits of a right by b bits: " << ( a >> b) << std::endl;
}