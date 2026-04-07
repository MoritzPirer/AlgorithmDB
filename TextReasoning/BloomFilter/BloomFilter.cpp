#include <cmath>
#include <iostream>
#include "BloomFilter.hpp"

size_t BloomFilter::getIndex(const std::string& word, size_t hash_index) {
    std::string key = word + std::to_string(hash_index);
    auto hash = m_hash_function(key);
    size_t index = hash % m_bitset.size();
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

bool BloomFilter::contains(const std::string& word) {
    for (size_t i = 0; i < c_num_hashings; i++)	{
        if (!m_bitset.isSet(getIndex(word, i))) {
            return false;	
        }
    }
    
    return true;
}
