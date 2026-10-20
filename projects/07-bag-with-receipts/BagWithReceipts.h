/*
FILE: BagWithReceipts.h
CLASS PROVIDED: BagWithReceipts (part of the namespace main_savitch_3)

TYPEDEFS, and MEMBER CONSTANTS

    typedef ___ value_type

        BagWithReceipts::value_types is the data type of the items in the BagWithReceipts.  It may be any of the C++ built-in types (int, char, etc), or a class with a default
        constructor, an assignment operator, and operators to test for equality 9x == y) and non-equality (x != y).

    typedef ___ size_type
        BagWithReceipts::size_type is the data type of any variable that keeps track of how many items are in a BagWithReceipts.

    static const size_type DEFAULT_CAPACITY = ___
        BagWithReceipts::DEFAULT_CAPACITY is the maximum number of items that a BagWithReceipts can hold.

    CONSTRUCTORS for the BagWithReceipts class:
        BagWithReceipts()
            Postcondition: The BagWithReceipts has been initialized as an empty BagWithReceipts.
    
    MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target)
            Postcondition: All copies of target have been removed from the BagWithReceipts.
            The return value is the number of copies removed (which could be zero).

        bool erase_one(const value_type& target)
            Postcondition: If target was in the BagWithReceipts, then one copy has been removed; 
            otherwise the BagWithReceipts is unchanged.  A true return value indicates that one
            copy was removed; false indicates that nothing was removed.

        void insert(const value_type& enrty)
            Precondition: size() < CAPACITY
            Postcondition: A new copy of entry has been added to the BagWithReceipts.

        void operator +=(const BagWithReceipts& addend)
            Precondition: size() + addend.size() <= CAPACITY.
            Postcondition: Each item in addend has been added to this BagWithReceipts.

    CONSTANT MEMBER FUNCTIONS 
        size_type size() const
            Postcondition: The return value is the total number if items in the BagWithReceipts.
        
        size_type count(const value_type& target) const
            postcondition: The return value is the number of times target is in the BagWithReceipts.

    NONMEMBER FUNCTIONS
        BagWithReceipts operator +(const BagWithReceipts& b1, const BagWithReceipts& b2)
            Precondition: b1.size() + b2.size() <= BagWithReceipts::CAPACITY
            Postcondition: The BagWithReceipts returned is the union of b1 and b2.

    VALUE SEMANTICS
        Assignments and the copy constructor may be used with BagWithReceipts objects.

*/

#ifndef MAIN_SAVITCH_BAG_WITH_RECEIPTS
#define MAIN_SAVITCH_BAG_WITH_RECEIPTS
#include <cstdlib>

namespace main_savitch_3 {

class BagWithReceipts {
public:
    // TYPEDEFS and MEMBER CONSTANTS
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 42;

    // Constructors
    BagWithReceipts(size_type initialCapacity = CAPACITY) { used = 0; }

    // Member functions (temporarily disabled)
    size_type count(const value_type& target) const;
    int insert(const value_type& entry);
    size_type size() const;
    // bool erase_one(const value_type& target);
    // void operator +=(const BagWithReceipts& addend);
    // size_type erase(const value_type& target);

private:
    size_type used;
    value_type data[CAPACITY];
    value_type in_use[CAPACITY];
};

// BagWithReceipts operator +(const BagWithReceipts& b1, const BagWithReceipts& b2);

}

#endif
