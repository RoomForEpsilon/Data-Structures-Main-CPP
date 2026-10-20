#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <cstdlib>


namespace main_savitch_3 {
class sequence {
public:
typedef double value_type;
typedef std::size_t size_type;
static const size_type CAPACITY = 10; 

sequence();
size_t size() const;
// Postcondition: the return value is the number of items in the sequence.

void start();
value_type current() const;
void advance();

bool is_item() const;
/*  
    Postcondition: A true return value indicates that there is a valid
    "current" item that can be obtained from the current member function.  
    A false return value indicates that there is no valid current item.
*/

void insert(const value_type& entry);
/*
    Precondition: size() < CAPACITY.
    Postcondition: A new copy of entry has been inserted in the sequence
    before the current item.  If there was no current item, then the new
    entry has been inserted at the front.  In either case, the new item is
    now the current item of the sequence.
*/

void attach(const value_type entry);
/*
    A new copy of entry has been inserted in the sequence after the current
    item.  If there was no current item, then the new entry has been attached
    to the end.  In either case, the new item is now the current item of the
    sequence.
*/

void remove_current();
/*
  Precondition: is_item returns true;
  Postcondition: The current item has been removed from the sequence, and the item
  after this (if there is one) is now the new current item.
*/

void remove(const value_type& entry);
/*
  Postcondition: There is no element of the sequence who has a value of entry.
*/

value_type operator[](size_type index) const;
/*
    This is the subscript operator.  If the subscript operator is performed on a 
    precondition: index < number of elements in array.
*/

// value_type operator[](size_type index);

private:
    value_type data[CAPACITY];
    size_t used;
    size_t current_index;
};
}
#endif