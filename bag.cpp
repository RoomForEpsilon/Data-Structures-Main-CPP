#include "bag.h"
#include <cassert>
#include <algorithm>

using namespace main_savitch_3;

bag::size_type bag::count(const value_type& target) const {
    size_t occurrences = 0;
    for (size_t i=0; i < used; i++) {
        if (data[i] == target)  occurrences++;
    }
    return occurrences;
}

void bag::insert(const value_type& entry) 
{
    assert(size() < CAPACITY);
    data[used] = entry;
    used++;
}

 bag::size_type bag::size() const {
    return used;
 }

 bool bag::erase_one(const value_type& target) {
    for (size_t i=0; i < size(); i++) {
        if (target == data[i]) {
            data[i] = data[used - 1];
            used--;
            return true;
        }
    }
    return false;
 }

 bag::size_type bag::erase(const bag::value_type& target) {
    size_t numRemoved = 0;
    size_t numOfTargets = count(target);

    for (size_t i=0; i < numOfTargets; i++) {
        erase_one(target);
        numRemoved++;
    }
    return numRemoved;
 }

 void bag::operator +=(const bag& addend) {
    assert(size() + addend.size() <= CAPACITY);
    int* iterator = std::copy(addend.data, addend.data + addend.used, data + used);
    int numCopied = (iterator - data) / sizeof(int);
    used += numCopied;
 }

bag operator +(const bag& b1, const bag& b2) {

    bag answer;
    assert(b1.size() + b2.size() <= bag::CAPACITY);

    answer += b1;
    answer += b2;

    return answer;
}