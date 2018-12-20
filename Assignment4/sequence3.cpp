#include <iostream>
#include <cassert>
#include "sequence3.h" // Note that the header file contains <cstdlib> ----> Which Provides size_t
#include "node1.h"


namespace data_structures_assignment3 {

//////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS and DESTRUCTOR:

    sequence::sequence() {
        cursor = nullptr;
        precursor = nullptr;
        head_ptr = nullptr;
        tail_ptr = nullptr;
        count = 0;
        // Everything is being set to NULL, since the object created, creates an initialized empty list.

        // Time Complexity:     O(1)
        // Reasoning:       Your creating 1 object, and just initializing the cursor, pre-cursor, head_ptr, and tail_ptr.
    }

    sequence::sequence(const sequence &source) {

        // So if the the source or list being copied is not empty,
        // AND if the precursor is not NULL, meaning that the list does not have 1 element

        head_ptr = nullptr; // So this is initialized as NULL.
        precursor = nullptr; // This is also initialized as NULL.
        cursor = nullptr;

        if(source.cursor == nullptr){
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            cursor = nullptr;
            precursor = nullptr;
            // This copies everything in the list from the head pointer to the tail pointer when the cursor, and pre-cursor go out of bounds.

        } else if (source.cursor == source.head_ptr) {
            list_copy(source.head_ptr, head_ptr, tail_ptr); // If the list only has 1 element
            cursor = head_ptr; // Set the cursor to the first element in the list
            precursor = nullptr; // Their is only 1 element in the list so the pre-cursor is set to NULL
            // If the source cursor is not at the first item in the list and greater than 0.

        } else {
            //Copying the list from 3 places
            list_piece(source.head_ptr, source.precursor, head_ptr, precursor);        // From head pointer to precursor  [excluding the last element]
            list_piece(source.precursor, source.cursor, precursor, cursor);         // From precursor to cursor        [excluding the last element]
            list_piece(source.cursor, source.tail_ptr, cursor, tail_ptr);           // From cursor to tail pointer     [excluding the last element]
           // To move the tail-ptr over to the next element we just inserted at the end of the list.
           if (tail_ptr == nullptr){
               tail_ptr = cursor;
           }
        }

        count = source.count; // The counts of the duplicate must be the same. However, the bug is that
        // when something is deleted from the source, the duplicate will have the wrong count. Damn.

        // Time Complexity:    O(n)     Linear Time
        // Reasoning:    The list may contain n elements.
    }

    sequence::~sequence() {
        list_clear(head_ptr); // Uses the list_clear function from the link list tool kit, node1.cpp.
        count = 0;
        cursor = nullptr;           // Set everything to NULL!
        tail_ptr = nullptr;
        precursor = nullptr;

        // Time Complexity:    O(n)     Linear Time
        // Reasoning:   The list may contain n elements.
        //  The list_clear function, is basically the list_head_remove function in a for loop that iterates up to n.
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////
    // MODIFICATION MEMBER FUNCTIONS:

    void sequence::start() {
        cursor = head_ptr;
        precursor = nullptr;
        // Time Complexity:     O(1)
        // Reasoning: All this function does is moe the cursor to the head_ptr the beginning of the linked list.
        // And Sets the pre-cursor to the nullptr;
    }

    void sequence::advance() {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
        // Time Complexity:     O(1)
        // Reasoning:   The list may contain n elements; However, this function advances the cursor only once per call.
    }

    void sequence::insert(const data_structures_assignment3::sequence::value_type &entry) {

        if (head_ptr == nullptr) {
            list_head_insert(head_ptr, entry);
            tail_ptr = head_ptr;
            cursor = head_ptr;
            precursor = nullptr;
            count += 1;
        } else if (cursor == nullptr || precursor == nullptr) {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = nullptr;
            count += 1;
        } else {
            list_insert(precursor, entry);
            cursor = precursor->link();
            count += 1;
        }
        // Time Complexity:     O(1)
        // Reasoning: It inserts a node into the linked list, that may contain n elements, only once per call.
    }

    void sequence::attach(const data_structures_assignment3::sequence::value_type &entry) {

        if (head_ptr == nullptr) {
            list_head_insert(head_ptr, entry);
            tail_ptr = head_ptr;
            cursor = head_ptr;
            precursor = nullptr;
            count += 1;
        } else if (cursor == nullptr || cursor == tail_ptr) {
            list_insert(tail_ptr, entry);
            precursor = tail_ptr;
            tail_ptr = tail_ptr->link();
            cursor = tail_ptr;
            count += 1;
        } else {
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
            count += 1;
        }
        // Time Complexity:     O(1)
        // Reasoning: It attaches a node into the linked list, that may contain n elements, only once per call.
    }

    void sequence::remove_current() {
        // This removes the current item in the current index at the current node!

        assert(is_item()); // Check Pre-Condition

        if (cursor == head_ptr) {
            if(count == 1){
                cursor = cursor->link();
                list_head_remove(head_ptr);
                cursor = nullptr;
                head_ptr = nullptr;
            } else {
                node* tmp = head_ptr;
                head_ptr = head_ptr->link();
                delete (tmp);
                cursor = head_ptr;
                precursor = nullptr;
            }
        } else {
            if (cursor == tail_ptr){
                tail_ptr = precursor; // This is to ensure the link is not broken.
            }
            cursor = cursor->link(); // however after the tail_ptr is null
            list_remove(precursor);

        }
        count--;
        // Time Complexity:     O(1)
        // Reasoning: It removes the current node from the linked list, that may contain n elements, only once per call.
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::operator=(const data_structures_assignment3::sequence &source) {

        if (this == &source) {
            return;
        }

        if (source.count == 0 || source.cursor == nullptr) {
        // If the list is empty

            list_clear(head_ptr);   // MUST DE-ALLOCATE THE MEMORY YOU DUMB-ASS!!!!!!!

            list_copy(source.head_ptr, head_ptr, tail_ptr); // copy the source list

            cursor = nullptr; // cursor is set to NULL;
            precursor = nullptr; // pre-cursor is also set to NULL; since the sequence is empty.

        } else if (source.cursor == source.head_ptr) {
            // If the list has only 1 element
            list_copy(source.head_ptr, head_ptr, tail_ptr); // If the list only has 1 element
            cursor = head_ptr; // Set the cursor to the first element in the list
            precursor = nullptr; // There is only 1 element in the list so the pre-cursor is set to NULL

        } else {
            // If the sequence has more than one element
            // divide the target list into two pieces one starting at the head and ending at the precursor
            // the other starting with the cursor and ending at the tail node

            // The memory has been de allocated thus, set everything to NULL...
            list_clear(head_ptr);

            list_piece(source.head_ptr, source.precursor, head_ptr, precursor);
            list_piece(source.precursor, source.cursor, precursor, cursor);
            list_piece(source.cursor, source.tail_ptr, cursor, tail_ptr);
            // link the two pieces together

            precursor = source.precursor;

        }
        count = source.count; // ensure the count is accurate.
        // Time Complexity:     O(n)     Linear Time
        // Reasoning: Copying the list using list_piece, and list_copy when the list in question can contain n elements.

    }


//////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CONSTANT MEMBER FUNCTIONS:

    sequence::size_type sequence::size() const {
        return list_length(head_ptr); // Return the number of items in the sequence
        // Time Complexity:     O(n)     Linear Time
        // Reasoning: This functions iterates from the head_ptr to the tail_ptr incrementing the count, on it's way. The list being counted may contain n elements.
    }

    bool sequence::is_item() const {
        return (cursor != nullptr); // No valid "current" item
        // Time Complexity:     O(1)
        // Reasoning: This function is boolean, all it does it return whether or not the cursor is not pointing to the nullptr, true or false.
    }

    sequence::value_type sequence::current() const {
        assert(is_item()); // checks to see if the list is empty or not
        return cursor->data(); // Returns the cursor or current *(de-refernced data) where the cursor is pointing to
        // Time Complexity:     O(1)
        // Reasoning: This function returns the data of the node, where the cursor is pointing at, even in a list containing n elements the
        // cursor is generally pointing toward 1 current node, at any given time. (This is assuming this is a Single linked list, not Double!).
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////

}

