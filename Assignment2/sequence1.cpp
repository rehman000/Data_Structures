// You must add all the code for this file.
// YOU MUST WRITE THE IMPLEMENTATION OVER HERE!!! :D

#include <iostream> // This is for cin >> and cout << .
#include <cstdlib> // This is for EXIT_SUCCESS
#include <cassert> // For Assert
#include "sequence1.h"


/////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR for the sequence class:
namespace data_structures_assignment_1 {

    sequence::sequence() {
        used = 0;
        current_index = 0; // This initializes the current_index value,
        // So what we have know is a empty array, since the other 30 index's have no values set.
    }

/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
// MODIFICATION MEMBER FUNCTIONS for the sequence class:

    void sequence::start() {
        current_index = 0; // Sets the current index i = 0;
        // std::cout << data[current_index] << std::endl;
    }


    void sequence::advance() {
        assert(is_item());
        current_index++;
    }


    void sequence::insert(const value_type &entry) {
        size_type i;
        assert(size() < CAPACITY);
        // So if there is no item in the array, we can set the index to the beginning at 0; And used is
        if (!is_item()) {
            current_index = 0;          // Front of the list[];
        }
        for (i = used; i > current_index; --i) {
            data[i] = data[i - 1]; // This shifts everything by 1 to the right.
        }
        data[current_index] = entry;  // If there is a current item.
        used++;
    }


    void sequence::attach(const value_type &entry) {

        assert(size() < CAPACITY);  // Used should be less than the CAPACITY = 30;
        if (is_item()) {
            for (std::size_t i = used; i > current_index; i--) {
                data[i] = data[i - 1]; // This shifts everything by 1
            }
            data[current_index + 1] = entry;
            current_index += 1;
            used++;
        } else {
            data[used] = entry;
            current_index = used;
            used++;
        }
    }

    void sequence::remove_current() {
        assert(is_item());      // If there is no item what are you goiing to erase?
        for (std::size_t i = current_index; i < used; i++) {
            data[i] = data[i + 1]; // This shifts everything by 1 to the left.
        }
        used--;
    }
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
// CONSTANT MEMBER FUNCTIONS for the sequence class:

    sequence::size_type sequence::size() const {
        return used; // Since index is always off by 1. index starts at 0;
    }

    bool data_structures_assignment_1::sequence::is_item() const {
        return current_index < used; // returns either true or false;
    }

    sequence::value_type sequence::current() const {
        return data[current_index]; // returns the current_index of the array[i];
    }

}
/////////////////////////////////////////////////////////////////////////////////
