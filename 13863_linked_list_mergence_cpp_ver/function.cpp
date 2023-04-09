/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

#include "function.h"

/**
 * Iterator
 */

// Dereference the iterator
template <typename T>
T &linked_list<T>::iterator::operator*() { return n->val; }

// Forward the itarator by pre-increment
template <typename T>
typename linked_list<T>::iterator linked_list<T>::iterator::operator++()
{
    n = n->next;
    return *this;
}

/**
 * Linked list
 */

// Merge two sorted linked list internally
template <typename T>
typename linked_list<T>::node *linked_list<T>::merge(node *lhs, node *rhs)
{
    node *head = NULL, **ptr = &head;
    for (node **cur = NULL; lhs && rhs; *cur = (*cur)->next, ptr = &(*ptr)->next)
    {
        cur = lhs->val < rhs->val ? &lhs : &rhs;
        *ptr = *cur;
    }
    *ptr = lhs ?: rhs;
    return head;
}

// Don't forget thess lines; otherwise compiler would not generate reference symbols and you'll get a CE.
template class linked_list<int>;
template class linked_list<string>;
