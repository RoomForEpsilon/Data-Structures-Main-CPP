#include "BagWithReceipts.h"
#include <cassert>
#include <algorithm>

using namespace main_savitch_3;

BagWithReceipts::size_type BagWithReceipts::count(const value_type& target) const {
    size_t occurrences = 0;
    for (size_t i=0; i < used; i++) {
        if (data[i] == target)  occurrences++;
    }
    return occurrences;
}

int BagWithReceipts::insert(const value_type& entry)
{
    assert(size() < CAPACITY);

    int receipt = -1;
    for (size_t i=0; i < CAPACITY; ++i) {
        if (in_use[i] == false) {
            in_use[i] = true;
            data[i] = entry;
            ++used;
            return i;
        }
    }
    throw new std::logic_error("This shouldn't be reached.");
}

BagWithReceipts::size_type BagWithReceipts::size() const {
    return used;
}

// bool BagWithReceipts::erase_one(const value_type& target) {
//     for (size_t i=0; i < size(); i++) {
//         if (target == data[i]) {
//             data[i] = data[used - 1];
//             used--;
//             return true;
//         }
//     }
//     return false;
// }

// BagWithReceipts::size_type BagWithReceipts::erase(const BagWithReceipts::value_type& target) {
//     size_t numRemoved = 0;
//     size_t numOfTargets = count(target);

//     for (size_t i=0; i < numOfTargets; i++) {
//         erase_one(target);
//         numRemoved++;
//     }
//     return numRemoved;
// }

// void BagWithReceipts::operator +=(const BagWithReceipts& addend) {
//     assert(size() + addend.size() <= CAPACITY);
//     int* iterator = std::copy(addend.data, addend.data + addend.used, data + used);
//     int numCopied = (iterator - data) / sizeof(int);
//     used += numCopied;
// }

// BagWithReceipts operator +(const BagWithReceipts& b1, const BagWithReceipts& b2) {
//     BagWithReceipts answer;
//     assert(b1.size() + b2.size() <= BagWithReceipts::CAPACITY);

//     answer += b1;
//     answer += b2;

//     return answer;
// }
