/*
FILE: bag.h
CLASS PROVIDED: bag (part of the namespace main_savitch_3)

TYPEDEFS, and MEMBER CONSTANTS

    typedef ___ value_type

        bag::value_types is the data type of the items in the bag.  It may be any of the C++ built-in types (int, char, etc), or a class with a default
        constructor, an assignment operator, and operators to test for equality 9x == y) and non-equality (x != y).

    typedef ___ size_type
        bag::size_type is the data type of any variable that keeps track of how many items are in a bag.

    static const size_type DEFAULT_CAPACITY = ___
        bag::DEFAULT_CAPACITY is the maximum number of items that a bag can hold.

    CONSTRUCTORS for the bag class:
        bag()
            Postcondition: The bag has been initialized as an empty bag.
    
    MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target)
            Postcondition: All copies of target have been removed from the bag.
            The return value is the number of copies removed (which could be zero).

        bool erase_one(const value_type& target)
            Postcondition: If target was in the bag, then one copy has been removed; 
            otherwise the bag is unchanged.  A true return value indicates that one
            copy was removed; false indicates that nothing was removed.

        void insert(const value_type& enrty)
            Precondition: size() < CAPACITY
            Postcondition: A new copy of entry has been added to the bag.

        void operator +=(const bag& addend)
            Precondition: size() + addend.size() <= CAPACITY.
            Postcondition: Each item in addend has been added to this bag.

    CONSTANT MEMBER FUNCTIONS 
        size_type size() const
            Postcondition: The return value is the total number if items in the bag.
        
        size_type count(const value_type& target) const
            postcondition: The return value is the number of times target is in the bag.

    NONMEMBER FUNCTIONS
        bag operator +(const bag& b1, const bag& b2)
            Precondition: b1.size() + b2.size() <= bag::CAPACITY
            Postcondition: The bag returned is the union of b1 and b2.

    VALUE SEMANTICS
        Assignments and the copy constructor may be used with bag objects.

*/

#ifndef MAIN_SAVITCH_BAG
#define MAIN_SAVITCH_BAG
#include <cstdlib>

namespace main_savitch_3 {

class bag {
public:
    // TYPEDEFS and MEMBER CONSTANTS
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 42;

    // Constructors
    bag(size_type initialCapacity = CAPACITY) { used = 0; }

    // MembER functions
    size_type count(const value_type& target) const;
    void insert(const value_type& entry);
    size_type size() const;
    bool erase_one(const value_type& target);
    void operator +=(const bag& addend);
    size_type erase(const value_type& target); 

private:
    size_type used;
    value_type data[initialCapacity];
};

bag operator +(const bag& b1, const bag& b2);

}

#endif