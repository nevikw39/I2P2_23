#include "function.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        node *lhs = malloc(sizeof(node)), *rhs, *cur = lhs;
        while (n--)
        {
            scanf("%d", &(cur->val));
            if (n)
                cur = cur->next = malloc(sizeof(node));
            else
                cur->next = NULL;
        }
        rhs = cur = malloc(sizeof(node));
        while (m--)
        {
            scanf("%d", &(cur->val));
            if (m)
                cur = cur->next = malloc(sizeof(node));
            else
                cur->next = NULL;
        }
        lhs = merge_linked_list(lhs, rhs);
        for (cur = lhs; cur; cur = cur->next)
            printf("%d%c", cur->val, " \n"[!cur->next]);
        while (lhs)
        {
            node *tmp = lhs;
            lhs = lhs->next;
            free(tmp);
        }
    }
    return 0;
}
