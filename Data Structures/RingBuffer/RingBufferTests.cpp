#include <iostream>
#include <cassert>
#include <cstring>

#include "RingBuffer.hpp"

void test_empty_buffer() {
    RingBuffer<5> rb;

    assert(rb.isEmpty());
    assert(!rb.isFull());
    assert(rb.countReadable() == 0);
    assert(rb.countWritable() == 5);

    char out[10];
    assert(rb.read(out, 3) == 0);
}

void test_full_buffer() {
    RingBuffer<5> rb;

    const char* data = "ABCDE";
    assert(rb.write(data, 5) == 5);

    assert(!rb.isEmpty());
    assert(rb.isFull());
    assert(rb.countReadable() == 5);
    assert(rb.countWritable() == 0);

    // cannot write more
    assert(rb.write("X", 1) == 0);
}

void test_basic_write_read() {
    RingBuffer<5> rb;

    const char* data = "ABC";
    assert(rb.write(data, 3) == 3);

    char out[5] = {};
    assert(rb.read(out, 3) == 3);
    assert(std::strncmp(out, "ABC", 3) == 0);

    assert(rb.isEmpty());
}

void test_partial_write() {
    RingBuffer<5> rb;

    const char* data = "ABCDEFG";
    assert(rb.write(data, 7) == 5); // only 5 fit

    assert(rb.isFull());
}

void test_partial_read() {
    RingBuffer<5> rb;

    rb.write("ABC", 3);

    char out[5] = {};
    assert(rb.read(out, 5) == 3); // only 3 available
    assert(std::strncmp(out, "ABC", 3) == 0);

    assert(rb.isEmpty());
}

void test_off_by_one_fill_then_read() {
    RingBuffer<5> rb;

    rb.write("ABCDE", 5);
    assert(rb.isFull());

    char out[5];
    // std::cout << rb.read(out, 4) << std::endl;
    assert(rb.read(out, 4) == 4);

    assert(!rb.isFull());
    assert(rb.countReadable() == 1);
    assert(rb.countWritable() == 4);
}

void test_wraparound_write() {
    RingBuffer<5> rb;

    rb.write("ABCDE", 5);

    char out[3];
    rb.read(out, 3); // free space at front

    // now write should wrap
    assert(rb.write("XYZ", 3) == 3);

    assert(rb.countReadable() == 5);
}

void test_wraparound_read_order() {
    RingBuffer<5> rb;

    rb.write("ABCDE", 5);

    char out1[3];
    rb.read(out1, 3); // consumes ABC

    rb.write("XY", 2); // wraparound write

    char out2[5] = {};
    assert(rb.read(out2, 4) == 4);

    // remaining should be: D E X Y
    assert(std::strncmp(out2, "DEXY", 4) == 0);
}

void test_alternating_read_write() {
    RingBuffer<2> rb;

    char out[2];

    assert(rb.write("A", 1) == 1);
    assert(rb.read(out, 1) == 1);
    assert(out[0] == 'A');

    assert(rb.write("B", 1) == 1);
    assert(rb.write("C", 1) == 1);
    assert(rb.isFull());

    assert(rb.read(out, 2) == 2);
    assert(std::strncmp(out, "BC", 2) == 0);

    assert(rb.isEmpty());
}

void test_exact_capacity_boundaries() {
    RingBuffer<5> rb;

    rb.write("ABCD", 4);
    assert(rb.countReadable() == 4);
    assert(rb.countWritable() == 1);

    rb.write("E", 1);
    assert(rb.isFull());

    char out[5];
    rb.read(out, 5);
    assert(rb.isEmpty());
}

int main() {
    test_empty_buffer();
    test_full_buffer();
    test_basic_write_read();
    test_partial_write();
    test_partial_read();
    test_off_by_one_fill_then_read();
    test_wraparound_write();
    test_wraparound_read_order();
    test_alternating_read_write();
    test_exact_capacity_boundaries();

    std::cout << "All tests passed.\n";
    return 0;
}