/*  INVARIANT
    1.  The number of items in the sequeence is stored in the member variable
        used.
    2.  For an empty sequence, we do not care what is stored in any of data; for
        a non-empty sequence, the items are stored in their sequence order from
        data[0] to data[used - 1], and we don't care what is stored in the rest
        of data.
    3.  If there is a current item, then it lies in data[current_index]; if there
        is no current item, then current_index equals used.  
*/

#include "sequence.h"
#include <stdexcept>
#include <cassert>

using namespace main_savitch_3;

sequence::sequence() {
    used = 0;
    current_index = 0;
    for (size_t i=0; i < CAPACITY; i++) {
        data[i] = -1.0;
    }
}
size_t sequence::size() const {
    return used;
}

void sequence::start() {
    current_index = 0;
}

sequence::value_type sequence::current() const{
    return data[current_index];
}

void sequence::advance() {
    ++current_index;
}

bool sequence::is_item() const {
    return current_index < used;
}

void sequence::insert(const value_type& entry) {
        if (size() >= CAPACITY) throw std::invalid_argument("The bag has overflowed it's capacity.");

        for (size_t i = used; i > current_index; i--) {
            data[i] = data[i-1];
        }
        data[current_index] = entry;
        used++;
}

void sequence::attach(const value_type entry) {
    if (size() >= CAPACITY) throw std::invalid_argument("The bag is over it's limit.");

    if (is_item()) {
        
        //Li: The subarray of data[used] to data[i] contains the last i elements of data.
        for (size_t i = used; i > current_index; i--) {
            data[i] = data[i-1];
        }
        data[current_index + 1] = entry;
        current_index++;
    } else {

        data[used] = entry;
        current_index = used;
    }
    used ++;
}

void sequence::remove_current() {
    if (!is_item()) throw std::domain_error("When calling remove_current, is_item() must be true");

    for (size_t i = current_index; i < used; i++) {
        data[i] = data[i+1];
    }
    used--;
}

void sequence::remove(const value_type& entry) {
    for(start(); is_item(); advance()) {
        if (current() == entry) {
            remove_current();
            current_index--;
        }
    }

}


sequence::value_type sequence::operator[](sequence::size_type index) const {
    assert (index < used);
    return data[index];
}

// sequence::value_type sequence::operator[](sequence::size_type index) {

// }