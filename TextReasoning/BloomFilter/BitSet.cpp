#include <exception>
#include <string>
#include <vector>

#include "BitSet.hpp"

	
	
BitSet::BitSet(size_t num_bits):
    c_number_of_bits{num_bits},
    m_bytes{std::make_unique<byte[]>(bytesNeeded(num_bits))}
    {}

constexpr size_t BitSet::bytesNeeded(size_t number_of_bits) {
    return (number_of_bits + c_bits_per_byte - 1) / c_bits_per_byte;
}

constexpr size_t BitSet::byteOf(size_t index) const {
    return index / c_bits_per_byte;
}

constexpr size_t BitSet::bitOf(size_t index) const {
    return index % c_bits_per_byte;
}

constexpr BitSet::byte BitSet::getBitmask(size_t index_within_byte) const {
    return 1 << (c_bits_per_byte - index_within_byte - 1);
}

void BitSet::checkRange(size_t index) const {
    if (index >= c_number_of_bits) {
        throw std::out_of_range("index " + std::to_string(index) + " is out of range!");
    }
}

void BitSet::set(size_t index) {
    checkRange(index);
    m_bytes[byteOf(index)] |= getBitmask(bitOf(index));
}

void BitSet::unset(size_t index) {
    checkRange(index);
    m_bytes[byteOf(index)] &= ~getBitmask(bitOf(index));
}

void BitSet::flip(size_t index) {
    checkRange(index);
    m_bytes[byteOf(index)] ^= getBitmask(bitOf(index));
}

bool BitSet::isSet(size_t index) const {
    checkRange(index);
    return (m_bytes[byteOf(index)] & getBitmask(bitOf(index))) != 0;
}



bool BitSet::operator[](size_t index) const {
    return isSet(index);
}

void BitSet::clear() {
    for (size_t i = 0; i < bytesNeeded(c_number_of_bits); i++) {
        m_bytes[i] = 0;
    }
}

size_t BitSet::size() const {
    return c_number_of_bits;
}

bool BitSet::areAllSet(const std::vector<size_t>& indices) const {
    for (size_t index : indices) {
        if (!isSet(index)) {
            return false;
        }
    }
    
    return true;
}

bool BitSet::areAnySet(const std::vector<size_t>& indices) const {
    for (size_t index : indices) {
        if (isSet(index)) {
            return true;
        }
    }
    
    return false;
}