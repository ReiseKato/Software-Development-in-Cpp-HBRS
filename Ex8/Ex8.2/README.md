Write a class `VirtualArray` that provides a member type `T` as an alias for `int` and that represents a number of existing `int`-arrays as if they were a contiguous one, in the following way:

- The constructor of the class takes
    - the number `n` of arrays,
    - an array of length `n`, containing the lengths of the base arrays, and
    - another array of length `n`, containing pointers to the base arrays.
    You might use copies of this data as internal representation of the virtual array. Optimization is possible but optional.

- The elements of the virtual array are the elements of the base arrays, which are virtually concatenated but factually unchanged. I.e., after the last element of the first array, the first of the second array is considered the next one. The length of the virtual array is the sum of the lengths of the base arrays.

- Overload the element access operator by member (required for this operator!) functions 

    `T const& operator[](std::size_t offset) const;`

    `T& operator[](std::size_t offset);`

    where `std::size_t` is an alias for the appropriate integer type for describing memory block sizes, defined in `<cstddef>`, and `offset` is any number from 0 to (*length of the virtual array*) - 1.

    To obtain the requested element, you have to identify the base array corresponding to the givenoffset. The basic approach is to decrement the offset by the lengths of the base arrays in their given order, in a loop, until the remaining offset is less than the length of the next base array. The requested element resides at this offset in this array.

    Consider how you might improve the internal representation of the virtual array to perform this computation/search more effectively.

- Provide a member class `Pointer` of `VirtualArray`, which (partially) models pointers into “arrays” of this type.
    
    - The constructor should take as arguments an actual pointer to the referred `VirtualArray` instance and an offset to the referred element therein as arguments. The implementation of the class might consist of copies of these two values.
    
    - The class should offer the operators
        - unary `*` and
        - binary `+` and `-`, the latter applicable to both `Pointer` and `std::ptrdiff_t` arguments.
    
    - How could the implementation of `Pointer` be improved in terms of performance?


# Solution

## Why This Design?

- **Templates?** Not used here since the question specifies `int` (but the class could be templated).

- **Pointer arithmetic in** `Pointer` simulates real pointers, supporting `+`, `-`, and dereferencing.

- **Offsets vector** stores cumulative sums to avoid repeated looping over lengths.

- **Array of pointers + lengths**: Gives flexibility to use different memory blocks seamlessly.

- **Element access (`[]`)**: Always goes through `locate()` to find correct base array and offset.

## Optimization Ideas

- Use binary search over offsets to improve access time from O(n) to O(log n).

- Precompute inverse map or segment tree if heavy random access is expected.

# Test script

| Feature               | Demonstrated In Line |
| --------------------- | -------------------- |
| Virtual array access  | Loop over `va[i]`    |
| Modification          | `va[2] = 99`         |
| Pointer arithmetic    | `ptr + i`, `ptr - i` |
| Dereferencing Pointer | `*ptr`, `*(ptr + i)` |

- When modifying va[2], it's actually modifying arr1[2], showing it's truly a view.

- Pointer works like a normal pointer but uses internal logic from VirtualArray.