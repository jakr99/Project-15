#include <iostream>
#include <cassert>
#include "list.h"

void testEmptyList() {
    List<int> l;
    assert(l.empty());
    assert(l.length() == 0);
}

void testAppendAndLength() {
    List<int> l;
    l.append(42);
    assert(!l.empty());
    assert(l.length() == 1);

    // Add more elements
    for (int i = 0; i < 5; ++i) {
        l.append(i);
    }
    assert(l.length() == 6);
}

void testPrepend() {
    List<int> l;
    l.prepend(42);
    assert(!l.empty());
    assert(l.length() == 1);

    // Add more elements
    for (int i = 0; i < 5; ++i) {
        l.prepend(i);
    }
    assert(l.length() == 6);
}

void testPopAndHead() {
    List<int> l;

    // Pop from an empty list should throw an exception
    try {
        l.pop();
    } catch (const out_of_range& e) {
        // Exception is expected
    }

    // Add elements and test pop and head
    for (int i = 0; i < 5; ++i) {
        l.append(i);
    }

    assert(l.head() == 0);
    l.pop();
    assert(l.head() == 1);
}

void testTail() {
    List<int> l;

    // Tail of an empty list should be empty
    assert(l.tail().empty());

    // Add elements and test tail
    for (int i = 0; i < 5; ++i) {
        l.append(i);
    }

    List<int> tail = l.tail();
    assert(tail.length() == 4);
    assert(tail.head() == 1);
}

// You can add more test cases as needed

int main() {
    // Run the tests
    testEmptyList();
    testAppendAndLength();
    testPrepend();
    testPopAndHead();
    testTail();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
