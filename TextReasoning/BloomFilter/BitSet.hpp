///
/// @file: BitSet.hpp
/// @description: An implementation of the bitset data structure. Creates a fixed size array of
/// bits and allows individual control of each bit
///
/// @date: 2026-04-06
/// @author: Moritz Pirer
///

#ifndef BIT_SET_HPP
#define BIT_SET_HPP

#include <stddef.h>
#include <memory>

class BitSet {
    /**
     * TODO:
     * - copy constructor
     * - count(): return number of set bits
     * - areAnySet(void): like areAnySet(vector), but for entire bitset
     * - areAllSet(void): like areAllSet(vector), but for entire bitset
     * - overload bitwise operators: & | ^ ~ &= |= ^= 
     */
private:
    using byte = uint8_t;
	static constexpr size_t c_bits_per_byte = 8; 
	
	const size_t c_number_of_bits = 0;
	std::unique_ptr<byte[]> m_bytes;
	
	/// @brief how many bytes are needed to store the number_of_bits bits
	constexpr size_t bytesNeeded(size_t number_of_bits);

	/// @brief calculates the byte that contains index (the first byte is 0)
	constexpr size_t byteOf(size_t index) const;

	/// @brief calculates the bit that contains index within its byte (0-7)
	constexpr size_t bitOf(size_t index) const; 
	
	/// @brief return a bitmask where only the given bit is 1 and all other bits 
	/// @param index_within_byte the bit that should be 1 (0 is the leftmost bit). Values >= c_bits_per_byte are undefined behavior
	/// @return a bitmask
	constexpr byte getBitmask(size_t index_within_byte) const;
	
	/// @brief check if index is a valid index in the bitset
    /// @throws std::out_of_range if index is invalid
	void checkRange(size_t index) const;
public:
	BitSet(size_t num_bits = 0);
    ~BitSet() = default;

    /// @brief sets the bit at the specified index to 1. If it was already set, nothing changes
    /// @param index the index to set
    /// @throws std::out_of_range if the index is too large
    void set(size_t index);
	
    /// @brief sets the bit at the specified index to 0. If it was already unset, nothing changes
    /// @param index the index to set
    /// @throws std::out_of_range if the index is too large
	void unset(size_t index);

    /// @brief changes the value of the bit at the specified index from 0 to 1 or from 1 to 0
    /// @param index the index to set
    /// @throws std::out_of_range if the index is too large
    void flip(size_t index);
	
	/// @brief checks if the given index is set to 1.
	/// @param index the index to check
	/// @return true if the bit is 1, false otherwise
    /// @throws std::out_of_range if the index is too large
	bool isSet(size_t index) const;
	
	/// @brief equivalent to isSet
	bool operator[](size_t index) const;

	/// @brief set all bits to 0
	void clear();
	
	/// @brief return the number of accessible bits
	size_t size() const;

	/// @brief checks all given indices and returns true if all specified bits are set to 1
	/// @param indices a vector of indices to check
	/// @return true if all bits are set, false if at least one is set to 0 (empty vector considered true)
	bool areAllSet(const std::vector<size_t>& indices) const;

	/// @brief checks all given indices and returns true if any of the specified bits is set to 1
	/// @param indices a vector of indices to check
	/// @return true if at least one bit is set, false if all bits set to 0 (empty vector considered false)
	bool areAnySet(const std::vector<size_t>& indices) const;
};

#endif // BIT_SET_HPP
