// FILE: node1.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t

namespace data_structures_assignment3 {
    size_t list_length(const node *head_ptr)
    // Library facilities used: cstdlib --->    Provides size_t
    {
        const node *cursor;
        size_t answer;

        answer = 0;
        for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
            ++answer;

        return answer;
    }

    void list_head_insert(node *&head_ptr, const node::value_type &entry) {
        head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node *previous_ptr, const node::value_type &entry) {
        node *insert_ptr;

        insert_ptr = new node(entry, previous_ptr->link());
        previous_ptr->set_link(insert_ptr);
    }

    node *list_search(node *head_ptr, const node::value_type &target)
    // Library facilities used: cstdlib  ---->   Provides size_t
    {
        node *cursor;

        for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
            if (target == cursor->data())
                return cursor;
        return nullptr;         // Returns us to the end of the linked list the Null pointer.
    }

    const node *list_search(const node *head_ptr, const node::value_type &target)
    // Library facilities used: cstdlib  ---->   Provides size_t
    {
        const node *cursor;

        for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
            if (target == cursor->data())
                return cursor;
        return nullptr;
    }

    node *list_locate(node *head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib  ---> Provides Assert, and size_t
    {
        node *cursor;
        size_t i;

        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != nullptr); i++)
            cursor = cursor->link();
        return cursor;
    }

    const node *list_locate(const node *head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib  ---> Provides Assert, and size_t
    {
        const node *cursor;
        size_t i;

        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != nullptr); i++)
            cursor = cursor->link();
        return cursor;
    }

    void list_head_remove(node *&head_ptr) {
        node *remove_ptr;

        remove_ptr = head_ptr;
        head_ptr = head_ptr->link();
        delete remove_ptr;
    }

    void list_remove(node *previous_ptr) {
        node *remove_ptr;

        remove_ptr = previous_ptr->link();
        previous_ptr->set_link(remove_ptr->link());
        delete remove_ptr;
    }

    void list_clear(node *&head_ptr)
    // Library facilities used: cstdlib --->    Provides size_t
    {
        while (head_ptr != nullptr)
            list_head_remove(head_ptr);
    }

    void list_copy(const node *source_ptr, node *&head_ptr, node *&tail_ptr)
    // Library facilities used: cstdlib --->    Provides size_t
    {
        head_ptr = nullptr;
        tail_ptr = nullptr;

        // Handle the case of the empty list.
        if (source_ptr == nullptr)
            return;

        // Make the head node for the newly created list, and put data in it.
        list_head_insert(head_ptr, source_ptr->data());
        tail_ptr = head_ptr;

        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        source_ptr = source_ptr->link();
        while (source_ptr != nullptr) {
            list_insert(tail_ptr, source_ptr->data());
            tail_ptr = tail_ptr->link();
            source_ptr = source_ptr->link();
        }
    }

    void list_piece(const node *start_ptr, const node *end_ptr, node *&head_ptr, node *&tail_ptr) {

        // Handle the case of the empty list.
        if (start_ptr == nullptr) {
            return;
        }

        tail_ptr = head_ptr;
        if (start_ptr == end_ptr) {
            return;
        }

        const node *temp_ptr;
        temp_ptr = start_ptr->link();


        // Make the head node for the newly created list, and put data in it.
        if (head_ptr == nullptr)
        {
            list_head_insert(head_ptr, start_ptr->data());
            tail_ptr = head_ptr;
        }
        // Copy the rest of the nodes one at a time, adding at the tail of new list.

        while (temp_ptr != end_ptr) {
            list_insert(tail_ptr, temp_ptr->data());
            temp_ptr = temp_ptr->link();
            tail_ptr = tail_ptr->link();
        }
        if(temp_ptr != nullptr){
        list_insert(tail_ptr, temp_ptr->data());
        tail_ptr = tail_ptr->link();
        } else {
            return;
        }


    }
}
