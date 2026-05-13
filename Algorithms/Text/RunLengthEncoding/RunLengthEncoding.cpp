#include <cassert>
#include "RunLengthEncoding.hpp"

void test_basic() {
    std::vector<int> vec = { 1, 2, 2, 3, 3, 3};
    auto encoded = RunLengthEncoding::encode(vec);
    assert(encoded.size() == 3);
    assert(encoded[0].value == 1 && encoded[0].count == 1);
    assert(encoded[1].value == 2 && encoded[1].count == 2);
    assert(encoded[2].value == 3 && encoded[2].count == 3);

    std::cout << "basic: ";
    RunLengthEncoding::printEncoding(encoded);
    auto decoded = RunLengthEncoding::decode(encoded);
    
    assert(vec == decoded);
}

void test_empty() {
    std::vector<int> vec;
    auto encoded = RunLengthEncoding::encode(vec);

    assert(encoded.empty());

    std::cout << "empty: ";
    RunLengthEncoding::printEncoding(encoded);
    auto decoded = RunLengthEncoding::decode(encoded);

    assert(decoded.empty());
}

void test_single() {
    std::vector<int> vec = {1};
    auto encoded = RunLengthEncoding::encode(vec);

    assert(encoded.size() == 1);
    assert(encoded[0].count == 1 && encoded[0].value == 1);

    std::cout << "single: ";
    RunLengthEncoding::printEncoding(encoded);
    auto decoded = RunLengthEncoding::decode(encoded);

    assert(decoded.size() == 1 && decoded[0] == 1);

}

void test_short_runs() {
    std::vector<int> vec = { 1, 2, 1, 3, 1, 3};
    auto encoded = RunLengthEncoding::encode(vec);
    assert(encoded.size() == 6);
    assert(encoded[0].value == 1 && encoded[0].count == 1);
    assert(encoded[1].value == 2 && encoded[1].count == 1);
    assert(encoded[2].value == 1 && encoded[2].count == 1);
    assert(encoded[3].value == 3 && encoded[3].count == 1);
    assert(encoded[4].value == 1 && encoded[4].count == 1);
    assert(encoded[5].value == 3 && encoded[5].count == 1);

    std::cout << "short runs: ";
    RunLengthEncoding::printEncoding(encoded);
    auto decoded = RunLengthEncoding::decode(encoded);
    
    assert(vec == decoded);

}

void test_non_numerical() {
    std::vector<std::string> vec {"hello", "hello", "world", "test", "world", "world", "world"};

    auto encoded = RunLengthEncoding::encode(vec);
    assert(encoded.size() == 4);
    assert(encoded[0].value == "hello" && encoded[0].count == 2);
    assert(encoded[1].value == "world" && encoded[1].count == 1);
    assert(encoded[2].value == "test" && encoded[2].count == 1);
    assert(encoded[3].value == "world" && encoded[3].count == 3);

    std::cout << "non-numerical: ";
    RunLengthEncoding::printEncoding(encoded);
    auto decoded = RunLengthEncoding::decode(encoded);
    
    assert(vec == decoded);
}

int main() {
    test_basic();
    test_single();
    test_short_runs();
    test_empty();
    test_non_numerical();
    return 0;
}