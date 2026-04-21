///
/// @file: BloomFilter.hpp
/// @description: A bloom filter is a probabilistic data structure that can check containment in a set.
///     False Negatives are impossible, and the chance for false positives can be somewhat controlled
///
/// TAGS:
/// domain/data-structure
/// paradigm/hashing
/// prop/probabilistic
///

#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

#include <functional>
#include "BitSet.hpp"

class BloomFilter {
private:
	const size_t c_num_bits = 0;
	const size_t c_num_hashings = 0;
	BitSet m_bitset; //std::bitset requires compile-time knowledge of size
	
    /// @brief stable hashing function using the FNV-1a hash
    /// @param value the value to hash
    /// @return the generated hash 
    /// @cite https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
    static size_t hash(const std::string& value);

	/// @brief calculates the index for the hash_index-th hash function of word
	/// @param word the word to hash
	/// @param hash_index how often the word was hashed already
	/// @return the index word got hashed to
	size_t getIndex(const std::string& word, size_t hash_index) const;

    /// @brief validates that x is a percentage (0 < x < 1)
    /// @throws std::invalid_argument if not a percentage
    static float validate(float x);
public:

	/// @brief creates a new empty filter
	/// @param num_items roughly how many items will be added. Adding significantly more items will increase error chance
	/// @param error_chance between 0 and 1, how high the chance of a false positive should be
	BloomFilter(size_t num_items, float error_chance);
    ~BloomFilter() = default;
    
	/// @brief resets the filter
	void clear();
	
	/// @brief inserts word into the filter
	void insert(const std::string& word);

	/// @brief inserts every word in words into the filter
    void insert(const std::vector<std::string>& words);

	/// @brief checks if word has been added to the filter. False is always correct, True has a chance to be false
    ///     (based on error_chance specified at creation)
	/// @param word the word to check for
	/// @return True if the word is (probably) added, false if the word is definately not added
	bool contains(const std::string& word) const;

    /// @brief load a list of words from an input stream
    /// @param input_stream 
    void loadWords(std::ifstream& input_stream);

    /// @brief load a list of bits representing previously parsed words from an input stream
    /// @param input_stream 
    void loadBits(std::ifstream& input_stream);

    /// @brief write the current state of bits representing parsed words to an output stream
    /// @param output_stream 
    void storeBits(std::ofstream& output_stream) const;
};

#endif //BLOOM_FILTER_HPP
