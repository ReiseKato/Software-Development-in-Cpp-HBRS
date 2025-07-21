#include "VirtualArray.hh"
#include <iostream>

int main()
{
    // Step 1: Create 3 actual arrays
    int arr1[] = {1, 2, 3};
    int arr2[] = {10, 20};
    int arr3[] = {100, 200, 300, 400};

    // Step 2: Prepare lengths and array-of-pointers
    std::size_t lengths[] = {3, 2, 4};
    int* arrays[] = {arr1, arr2, arr3};

    // Step 3: Create the VirtualArray
    VirtualArray va(3, lengths, arrays);

    // Step 4: Access all elements using operator[]
    std::cout << "VirtualArray contents: ";
    for (std::size_t i = 0; i < va.size(); ++i) {
        std::cout << va[i] << " ";
    }
    std::cout << "\n";

    // Step 5: Modify an element
    va[2] = 99;
    std::cout << "Modified 3rd element: " << va[2] << "\n";

    // Step 6: Use Pointer class to walk through array
    VirtualArray::Pointer ptr(&va, 0);
    std::cout << "Walking through with Pointer: ";
    for (std::size_t i = 0; i < va.size(); ++i) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << "\n";

    // Step 7: Demonstrate Pointer arithmetic
    auto ptr3 = ptr + 3;
    auto ptr1 = ptr3 - 2;
    std::cout << "Pointer at index 3: " << *ptr3 << "\n";
    std::cout << "Pointer at index 1 (from 3 - 2): " << *ptr1 << "\n";

    return 0;
}
