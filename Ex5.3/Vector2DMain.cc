#include <iostream>
#include "linalg/Vector2D.hh"

int main() {
    linalg::Vector2D v;
    std::cin >> v;
    std::cout << "Input was: " << v << std::endl;
    v += v;
    std::cout << "Self-addition yields: " << v << std::endl;
    return 0;
}
