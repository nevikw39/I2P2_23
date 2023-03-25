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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int n, m, *bit; // Fenwick tree

int lowbit(int x) { return x & -x;}

void update(int x, int v)
{
    for (; x < 1 << m; x += lowbit(x))
        bit[x] += v;
}

int query(int x)
{
    int y = 0;
    for (; x; x -= lowbit(x))
        y += bit[x];
    return y;
}

int find_by_order(int k)
{
    int y = 0;
    for (int i = 1 << m, s = 0; i; i >>= 1)
        if (y + i < 1 << m && s + bit[y + i] < k)
            s += bit[y += i];
    return y + 1;
}

int main()
{
    int k, x = 0;
    scanf("%d%d", &n, &k);
    m = ceil(log2(n));
    bit = (int *) calloc(1 << m, sizeof(int));
    for (int i = 1; i <= n; i++)
        update(i, 1);
    for (int i = n; i;)
    {
        x = find_by_order((query(x) + k) % i-- + 1);
        printf("%d\n", x);
        update(x, -1);
    }
    return 0;
}
