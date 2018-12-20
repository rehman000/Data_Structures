#include <iostream>
#include <algorithm>  // std::copy function.
#include <random>
#include "sequence2.h"
#include <cstdlib>  // Provides size_t

namespace data_structures_assignment_3 {

//////////////////////////////////////////////////////////////////////////////////////////
    // CONSTRUCTOR:

    sequence::sequence(size_type initial_capacity){
        data = new value_type[initial_capacity]; // Heap memory.
        used = 0;
        current_index = 0;
        capacity = initial_capacity; // This is what we set, if nothing is set, we will have defualt 30.
    }

    sequence::sequence(const data_structures_assignment_3::sequence &source){
        // The arrays uses pointers thus setting them equal to one another is not an option.
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_index = source.current_index;
        std::copy(source.data, source.data + used, data);
    }

    sequence::~sequence(){
        delete[] data; // This is deletes the entire array, when the destructor is called;
    }

//////////////////////////////////////////////////////////////////////////////////////////
    // MODIFICATION MEMBER FUNCTIONS:

    void sequence::start(){
        current_index = 0;
    }

    void sequence::advance(){
        assert(is_item());
        current_index++;
    }

    void sequence::insert(const value_type &entry){
        /* assert(size() < DEFAULT_CAPACITY);
        // So if there is no item in the array, we can set the index to the beginning at 0; And used is
         So this is no longer necessary! :-) */

        if(used == capacity){
            resize(used +1); // The resize Function allows us to change the DEFAULT_CAPACITY to our needs.
        }
        if (!is_item()) {
            current_index = 0;          // Front of the list[];
        }
        size_type i;
        for (i = used; i > current_index; --i) {
            data[i] = data[i - 1]; // This shifts everything by 1 to the right.
        }
        data[current_index] = entry;  // If there is a current item.
        used++;
    }
    // Insert and attach statements must include an if statement implementing the resize();

    void sequence::attach(const value_type &entry){
        // assert(size() < DEFAULT_CAPACITY);  // Used should be less than the CAPACITY = 30;

        if(used == capacity){
            resize(used +1); // The resize Function allows us to change the DEFAULT_CAPACITY to our needs.
        }

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

    void sequence::remove_current(){
        assert(is_item());
        for(std::size_t i = current_index; i < used; i++){
            data[i] = data[i+1];
        }
        used--;
    }


    void sequence::resize(size_type new_capacity){

        value_type *new_array;
        if(new_capacity == capacity){
            return;
            // So if the new array has the same DEFAULT_CAPACITY, you don't need to resize it,
            // Just skip this one!
        } else {
            if (new_capacity < used) {
                new_capacity = used;
            }
            if (new_capacity > used) {
                new_array = new value_type[new_capacity];
                std::copy(data, data + used, new_array);
                delete[] data;
                data = new_array;
                capacity = new_capacity;
            }
        }
    }

//////////////////////////////////////////////////////////////////////////////////////////
// EXTRA CREDIT:

    // NON-MEMBER FUNCTION:
    sequence operator+(const data_structures_assignment_3::sequence& S2, const data_structures_assignment_3::sequence& S3) {
        sequence S1;

        S1+=S2; // This adds everything from S1 into S1;
        S1+=S3; // This adds everything from S2 into S1;

        return S1; // This returns the whole sequence of S1 (with all the values of S2 and S3);
    }

    // MEMBER FUNCTION
    void sequence::operator+=(const data_structures_assignment_3::sequence &source){
        if (used + source.used > capacity){
            resize(used + source.used);
        }
        std::copy(source.data, source.data + source.used, data + used);
        // This is the same as using a for loop, and += the data in the array as i and j increment.
        used += source.used;
    }

    // MEMBER FUNCTION:
    sequence::value_type sequence::operator[](sequence::size_type index) const {

        assert(index < capacity); // Index cannot be greater then capacity.
        assert(index < used); // Index cannot be greater than used.
        // This does not the program compile if the user, tries to look up an index that is within the capacity, but it is not used.

        return data[index];
    }

//////////////////////////////////////////////////////////////////////////////////////////

    void sequence::operator=(const sequence &source){
        // Here we used the copy ();
        if (this == &source){
            return;
        }

        value_type *new_data;

        if(capacity != source.capacity){
            new_data = new value_type[source.capacity];
            delete[] data;
            data = new_data;
            capacity = source.capacity;
        }
        current_index = source.current_index;
        used = source.used;
        std::copy(source.data, source.data + used, data);
    }


//////////////////////////////////////////////////////////////////////////////////////////
// CONSTANT MEMBER FUNCTIONS:

   sequence::size_type sequence::size() const{
       return used;
    }

    bool data_structures_assignment_3::sequence::is_item() const{
        return current_index < used;
    }

    sequence::value_type sequence::current() const{
        return data[current_index];
    }

    void sequence::print() {
        size_type i;
        for(i = 0; i < used; i++){
            std::cout << data[i] << std::endl;
        }
    }


//////////////////////////////////////////////////////////////////////////////////////////


}


