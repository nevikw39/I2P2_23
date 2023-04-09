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

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _edge
{
    int v;
    int64_t w;
    struct _edge *next;
} edge;
edge **head;

void update(int64_t *ptr, int64_t x)
{
    if (*ptr < x)
        *ptr = x;
}

int64_t *dfs(int u, int p)
{
    int64_t *arr = malloc(sizeof(int64_t) << 1);
    arr[0] = 0;
    arr[1] = 0;
    for (edge *ptr = head[u]; ptr; ptr = ptr->next)
        if (ptr->v != p)
        {
            int64_t *brr = dfs(ptr->v, u);
            update(arr, brr[0]);
            update(arr, arr[1] + ptr->w + brr[1]);
            update(arr + 1, ptr->w + brr[1]);
            free(brr);
        }
    return arr;
}

edge *new_edge(int v, int w, edge *next)
{
    edge *y = malloc(sizeof(edge));
    *y = (edge){.v = v, .w = w, .next = next};
    return y;
}

int main()
{
    int n;
    scanf("%d", &n);
    head = calloc(n, sizeof(edge *));
    int64_t r = 0;
    for (int i = 1, a, b, w; i < n; i++)
    {
        scanf("%d%d%d", &a, &b, &w);
        head[a] = new_edge(b, w, head[a]);
        head[b] = new_edge(a, w, head[b]);
        r += w;
    }
    int64_t *arr = dfs(0, -1);
    fprintf(stderr, "\t%d %d %d\n", r, r << 1, *arr);
    printf("%" PRId64 "\n", (r << 1) - *arr);
    return 0;
}
