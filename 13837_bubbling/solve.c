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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void iter_swap(int *l, int *r) { *l ^= *r ^= *l ^= *r; }

void bubble_sort(int *begin, int *end)
{
    int cmp = 0, swaps = 0;
    for (; begin < end; end--)
    {
        bool swapped = false;
        for (int *ptr = begin + 1; ptr < end; ptr++)
        {
            ++cmp;
            if (*(ptr - 1) > *ptr)
            {
                ++swaps;
                iter_swap(ptr - 1, ptr);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    printf("%d %d\n", cmp, swaps);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int *ptr = arr; ptr < arr + n; ptr++)
        scanf("%d", ptr);
    bubble_sort(arr, arr + n);
    free(arr);
    return 0;
}
