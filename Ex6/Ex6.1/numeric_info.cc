#include <limits>
#include <iostream>

#define numeric_info(T) print_numeric_info<T>(#T) // # for stringification

template<typename T>
void print_numeric_info(const std::string& type_name)
{
    using limits = std::numeric_limits<T>;

    std::cout << type_name << "\t\t"
            << sizeof(T) * 8 << "\t\t"
            << static_cast<int>(limits::min()) << "\t"
            << static_cast<int>(limits::max()) << "\n";

}

int main()
{
    std::cout << "Type\t\tSize (bits)\tMin\t\tMax\n";
    std::cout << "--------------------------------------------------------\n";

    numeric_info(short);
    numeric_info(int);
    numeric_info(char);

    return 0;
}