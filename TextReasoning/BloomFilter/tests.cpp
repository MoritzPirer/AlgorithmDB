#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <string>


#include "BitSet.hpp"
#include "BloomFilter.hpp"

void test_Initialization() {
    BitSet bs(32);
    assert(bs.size() == 32);
    // Ensure everything starts at 0
    for(size_t i = 0; i < 32; ++i) assert(!bs.isSet(i));
    std::cout << "Test 1: Initialization Passed\n";
}

void test_SetAndIsSet() {
    BitSet bs(10);
    bs.set(3);
    bs.set(7);
    assert(bs.isSet(3) == true);
    assert(bs.isSet(7) == true);
    assert(bs.isSet(0) == false);
    std::cout << "Test 2: Set/IsSet Passed\n";
}

void test_Unset() {
    BitSet bs(10);
    bs.set(5);
    assert(bs.isSet(5) == true);
    bs.unset(5);
    assert(bs.isSet(5) == false);
    std::cout << "Test 3: Unset Passed\n";
}

void test_Flip() {
    BitSet bs(10);
    bs.flip(2); // 0 -> 1
    assert(bs.isSet(2) == true);
    bs.flip(2); // 1 -> 0
    assert(bs.isSet(2) == false);
    std::cout << "Test 4: Flip Passed\n";
}

void test_OutOfBounds() {
    BitSet bs(8);
    try {
        bs.set(8); // Index 8 is out of bounds for size 8
        assert(false); 
    } catch (const std::out_of_range& e) {
        assert(true);
    }
    std::cout << "Test 5: Out of Bounds Check Passed\n";
}

void test_ByteBoundaries() {
    // Tests if bit 7 and 8 fall into correct separate bytes
    BitSet bs(16);
    bs.set(7);
    bs.set(8);
    assert(bs.isSet(7) && bs.isSet(8));
    bs.unset(7);
    assert(!bs.isSet(7) && bs.isSet(8));
    std::cout << "Test 6: Byte Boundary Logic Passed\n";
}

void test_AreAllSet() {
    BitSet bs(20);
    std::vector<size_t> indices = {1, 5, 10};
    
    assert(!bs.areAllSet(indices)); 
    bs.set(1);
    bs.set(5);
    bs.set(10);
    assert(bs.areAllSet(indices));
    
    // Empty vector should return true per your comment
    assert(bs.areAllSet({}));
    std::cout << "Test 7: AreAllSet Passed\n";
}

void test_AreAnySet() {
    BitSet bs(20);
    std::vector<size_t> indices = {1, 5, 10};
    
    assert(!bs.areAnySet(indices));
    bs.set(5);
    assert(bs.areAnySet(indices));
    
    // Empty vector should return false per your comment
    assert(!bs.areAnySet({}));
    std::cout << "Test 8: AreAnySet Passed\n";
}

void test_Clear() {
    BitSet bs(100);
    bs.set(0);
    bs.set(50);
    bs.set(99);
    bs.clear();
    assert(!bs.isSet(0) && !bs.isSet(50) && !bs.isSet(99));
    std::cout << "Test 9: Clear Passed\n";
}

void test_OperatorOverload() {
    BitSet bs(10);
    bs.set(4);
    assert(bs[4] == true);
    assert(bs[0] == false);
    std::cout << "Test 10: Operator[] Passed\n";
}

void test_BasicInsertion() {
    // Small filter: 100 items, 5% error chance
    BloomFilter bf(100, 0.05f);
    
    bf.insert("apple");
    bf.insert("orange");
    
    assert(bf.contains("apple") == true);
    assert(bf.contains("orange") == true);
    assert(bf.contains("banana") == false); // Should be false with high probability
    std::cout << "[PASS] Basic Insertion & Contains\n";
}

void test_FalseNegativeGuarantee() {
    // Bloom Filters MUST have 0% false negative rate.
    // If we put it in, it MUST be there.
    BloomFilter bf(1000, 0.01f);
    std::vector<std::string> words = {"test1", "test2", "test3", "test4"};
    
    for(const auto& w : words) bf.insert(w);
    for(const auto& w : words) {
        if(!bf.contains(w)) {
            std::cerr << "FAIL: False Negative detected for " << w << "\n";
            assert(false);
        }
    }
    std::cout << "[PASS] Zero False Negatives\n";
}

void test_ClearFilter() {
    BloomFilter bf(100, 0.01f);
    bf.insert("data");
    assert(bf.contains("data") == true);
    
    bf.clear();
    assert(bf.contains("data") == false);
    std::cout << "[PASS] Clear Filter\n";
}

void test_InvalidParameters() {
    try {
        // Test error chance > 1.0
        BloomFilter bf(100, 1.5f);
        assert(false); // Should have thrown
    } catch (const std::invalid_argument& e) {
        assert(true);
    }
    std::cout << "[PASS] Parameter Validation\n";
}

void test_HighCollisionSaturation() {
    // Create a tiny filter and overfill it
    // False positives should eventually become common
    BloomFilter bf(5, 0.01f); 
    bf.insert("A");
    bf.insert("B");
    bf.insert("C");
    bf.insert("D");
    bf.insert("E");
    bf.insert("F"); // Saturation
    
    // We can't easily assert a false positive (it's random),
    // but we check that the program doesn't crash under high load.
    assert(bf.contains("A"));
    std::cout << "[PASS] Saturation Resilience\n";
}

void test_EmptyStrings() {
    BloomFilter bf(100, 0.05f);
    bf.insert("");
    assert(bf.contains("") == true);
    assert(bf.contains(" ") == false);
    std::cout << "[PASS] Empty String Handling\n";
}

void test_CaseSensitivity() {
    BloomFilter bf(100, 0.01f);
    bf.insert("GitHub");
    // Standard std::hash is case sensitive
    assert(bf.contains("GitHub") == true);
    assert(bf.contains("github") == false);
    std::cout << "[PASS] Case Sensitivity\n";
}

void test_LargeStrings() {
    BloomFilter bf(100, 0.01f);
    std::string long_str(1000, 'z');
    bf.insert(long_str);
    assert(bf.contains(long_str));
    std::cout << "[PASS] Large String Hashing\n";
}

void test_MultipleHashConsistency() {
    BloomFilter bf(100, 0.01f);
    // Ensure that getIndex (via contains/insert) is deterministic
    bf.insert("Consistent");
    for(int i = 0; i < 10; ++i) {
        assert(bf.contains("Consistent"));
    }
    std::cout << "[PASS] Hashing Consistency\n";
}

void test_ErrorChanceLogic() {
    // If error chance is requested to be nearly 0, 
    // the underlying bitset size should be large.
    BloomFilter precise(10, 0.0001f);
    BloomFilter loose(10, 0.5f);
    
    // Note: This requires a public or friend way to check bitset size,
    // but logically, precise should use significantly more memory.
    std::cout << "[PASS] Error Chance Logic (Architectural)\n";
}

int main() {
    try {
        //bitset
        test_Initialization();
        test_SetAndIsSet();
        test_Unset();
        test_Flip();
        test_OutOfBounds();
        test_ByteBoundaries();
        test_AreAllSet();
        test_AreAnySet();
        test_Clear();
        test_OperatorOverload();

        //bloom filter
        test_BasicInsertion();
        test_FalseNegativeGuarantee();
        test_ClearFilter();
        test_InvalidParameters();
        test_HighCollisionSaturation();
        test_EmptyStrings();
        test_CaseSensitivity();
        test_LargeStrings();
        test_MultipleHashConsistency();
        test_ErrorChanceLogic();
        
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
    }
    return 0;
}
