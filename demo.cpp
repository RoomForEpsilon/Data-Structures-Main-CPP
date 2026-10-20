#include <cstdlib>
#include <cstdio>
#include <cassert>
#include "bag.h"

using namespace main_savitch_3;

int main() {

    bag b;
    
    assert(b.count(7) == 0);

    assert(b.count(-1) == 0);
    b.insert(-1);
    assert(b.count(-1) == 1);
    b.erase_one(-1);
    assert(b.count(-1) == 0);
    b.erase_one(-1);
    assert(b.count(-1) == 0);

    for (size_t i=0; i < 42; i++) {
        assert(b.size() == i);
        b.insert(0);
        assert(b.count(0) == (i + 1) );
    }
    bag mixed;
    mixed.insert(4);
    mixed.insert(7);
    mixed.insert(4);
    mixed.insert(-1);
    mixed.insert(4);

    assert(mixed.count(4) == 3);
    assert(mixed.count(7) == 1);
    assert(mixed.count(-1) == 1);
    assert(mixed.count(99) == 0);

    assert(b.count(0) == 42);
    b.erase(0);
    assert(b.count(0) == 0);
    mixed.erase(4);
    assert(mixed.count(4) == 0);
    assert(mixed.count(-1) == 1);

    // operator += tests
    bag a, c;
    a += c;
    assert(a.size() == 0 && c.size() == 0);
    a.insert(0);
    a += c;
    assert(a.size() == 1 && c.size() == 0);
    c.insert(1);
    a += c;
    assert(a.size() == 2 && c.size() == 1);
    assert(a.count(0) == 1 && a.count(1) == 1 && a.count(99) == 0);

    return  EXIT_SUCCESS;   
}