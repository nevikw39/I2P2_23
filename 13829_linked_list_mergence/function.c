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

#include <stddef.h>
#include <stdint.h>

#include "function.h"

node *merge_linked_list(node *lhs, node *rhs)
{
    node *head = NULL, **ptr = &head;
    for (node **cur = NULL; lhs && rhs; *cur = (*cur)->next, ptr = &(*ptr)->next)
    {
        cur = lhs->val < rhs->val ? &lhs : &rhs;
        *ptr = *cur;
    }
    *ptr = (uintptr_t) lhs | (uintptr_t) rhs;
    return head;
}
