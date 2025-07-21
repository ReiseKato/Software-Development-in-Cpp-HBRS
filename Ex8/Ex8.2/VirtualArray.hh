#ifndef VIRTUAL_ARRAY_HH
#define VIRTUAL_ARRAY_HH

#include <iostream>
#include <vector>

class VirtualArray
{
    public:
        using T = int;
        VirtualArray(std::size_t n, std::size_t* lengths, T** arrays);

        std::size_t size() const;

        T const& operator[](std::size_t offset) const;
        T& operator[](std::size_t offset);

        class Pointer
        {
            public:
                Pointer(VirtualArray* array, std::size_t offset);

                T& operator*() const;
                Pointer operator+(std::ptrdiff_t diff) const;
                Pointer operator-(std::ptrdiff_t diff) const;
            
            private:
                VirtualArray* baseArray_;
                std::size_t offset_;
        };

    private:
        std::size_t numArrays_;
        std::vector<std::size_t> lengths_;
        std::vector<T*> arrays_;
        std::vector<std::size_t> offsets;  // cumulative offsets for optimization
        std::size_t totalLength_;

        void computeOffsets();             // builds prefix sum for fast lookup
        std::pair<std::size_t, std::size_t> locate(std::size_t offset) const;
};


#endif // VIRTUAL_ARRAY_HH