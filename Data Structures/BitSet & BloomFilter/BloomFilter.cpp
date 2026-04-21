#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

#include "BloomFilter.hpp"

size_t BloomFilter::hash(const std::string& value) {
    size_t hash = 1469598103934665603ULL;
    for (char c : value) {
        hash ^= (unsigned char)c;
        hash *= 1099511628211ULL;
    }
    return hash;
}

size_t BloomFilter::getIndex(const std::string& word, size_t hash_index) const {
    std::string key = word + std::to_string(hash_index);
    auto hashed = hash(key);
    size_t index = hashed % m_bitset.size();
    return index;	
}

float BloomFilter::validate(float x) {
    if (x <= 0.0f || x >= 1.0f) {
        throw std::invalid_argument("Percentage must be between 0 and 1");
    }
    return x;
}

BloomFilter::BloomFilter(size_t num_items, float error_chance):
    c_num_bits{static_cast<size_t>(std::ceil(-(num_items * log(validate(error_chance))) / pow(log(2), 2)))}, 
    c_num_hashings{static_cast<size_t>(std::ceil(c_num_bits/num_items * log(2)))},
    m_bitset{c_num_bits}
    {}
    
void BloomFilter::clear() {
    m_bitset.clear();
}

void BloomFilter::insert(const std::string& word) {
    for (size_t i = 0; i < c_num_hashings; i++) {
        m_bitset.set(getIndex(word, i));
    }
}

void BloomFilter::insert(const std::vector<std::string>& words) {
    for (const std::string& word : words) {
        insert(word);
    }
}

bool BloomFilter::contains(const std::string& word) const {
    for (size_t i = 0; i < c_num_hashings; i++)	{
        if (!m_bitset.isSet(getIndex(word, i))) {
            return false;	
        }
    }
    
    return true;
}

void BloomFilter::loadWords(std::ifstream& input_stream) {
    std::string line;
    while (std::getline(input_stream, line)) {
        //split into words
        int start = 0;
        int end = 0;
        char delimiter = ' ';
        std::vector<std::string> words;

        while ((start = line.find_first_not_of(delimiter, end)) != std::string::npos) {
            end = line.find(delimiter, start);
            words.push_back(line.substr(start, end - start));
        }

        insert(words);
    }
}

void BloomFilter::loadBits(std::ifstream& input_stream) {
    // replace self with new bloom filter 
    // 1st line = num_bits
    // 2nd line = num_hashings
    //every other line = 8 bits
}

void BloomFilter::storeBits(std::ofstream& output_stream) const {
    //write num_bits
    //write num_hashings
    //write one bit per line
}