///
/// FNV is a non-cryptographic hash function that is very simple and fast to compute.
/// It is intended for use in Hash Tables, checksums and Bloom Filters
///
/// TAGS:
/// paradigm/hashing

#include <stddef.h>
#include <string>

#define FNV_BASIS 1469598103934665603ULL
#define FNV_PRIME 1099511628211ULL

size_t FNV_1(const std::string& value) {
    size_t hash = FNV_BASIS;
    for (char c : value) {
        hash *= FNV_PRIME;
        hash ^= (unsigned char) c;
    }
    return hash;
}

/// @brief differs from FNV-1 only in the order of multiplication and xor
size_t FNV_1a(const std::string& value) {
    size_t hash = FNV_BASIS;
    for (char c : value) {
        hash ^= (unsigned char) c;
        hash *= FNV_PRIME;
    }
    return hash;
}

/// @brief deprecated. differs from FNV-1 only by using 0 as a base, which can lead to worse hashing if multiple bytes are 0
size_t FNV_0(const std::string& value) {
    size_t hash = 0;
    for (char c : value) {
        hash *= FNV_PRIME;
        hash ^= (unsigned char) c;
    }
    return hash;
}