#include "VirtualArray.hh"

VirtualArray::VirtualArray(std::size_t n, std::size_t* lengths, T** arrays)
    : numArrays_(n), lengths_(lengths, lengths + n), arrays_(arrays, arrays + n), totalLength_(0)
{
    computeOffsets();
}

void VirtualArray::computeOffsets()
{
    std::size_t runningSum = 0;
    for (std::size_t len : lengths_) {
        offsets.push_back(runningSum);
        runningSum += len;
    }
    totalLength_ = runningSum;
}

std::size_t VirtualArray::size() const
{
    return totalLength_;
}

std::pair<std::size_t, std::size_t> VirtualArray::locate(std::size_t offset) const
{
    if (offset >= totalLength_)
        throw std::out_of_range("Offset out of range");

    for (std::size_t i = 0; i < numArrays_; ++i) {
        if (offset < offsets[i] + lengths_[i]) {
            return {i, offset - offsets[i]};
        }
    }
    throw std::runtime_error("Invalid offset computation");
}

VirtualArray::T const& VirtualArray::operator[](std::size_t offset) const
{
    auto result = locate(offset);
    std::size_t i = result.first;
    std::size_t localOffset = result.second;
    return arrays_[i][localOffset];
}

VirtualArray::T& VirtualArray::operator[](std::size_t offset)
{
    auto result = locate(offset);
    std::size_t i = result.first;
    std::size_t localOffset = result.second;
    return arrays_[i][localOffset];
}

// --- Pointer member functions ---

VirtualArray::Pointer::Pointer(VirtualArray* b, std::size_t off)
    : baseArray_(b), offset_(off) {}

VirtualArray::T& VirtualArray::Pointer::operator*() const {
    return (*baseArray_)[offset_];
}

VirtualArray::Pointer VirtualArray::Pointer::operator+(std::ptrdiff_t diff) const {
    return Pointer(baseArray_, offset_ + diff);
}

VirtualArray::Pointer VirtualArray::Pointer::operator-(std::ptrdiff_t diff) const {
    return Pointer(baseArray_, offset_ - diff);
}