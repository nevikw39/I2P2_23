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

typedef struct _treap
{
    struct _treap *l, *r;
    int pri, key, sz;
} treap;

int sz(treap *t) { return t ? t->sz : 0; }

void pull(treap *t) { t->sz = sz(t->l) + 1 + sz(t->r); }

treap *merge(treap *a, treap *b)
{
    if (!a || !b)
        return a ?: b;
    if (a->pri > b->pri)
    {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    b->l = merge(a, b->l);
    pull(b);
    return b;
}

void split(treap *t, int k, treap **a, treap **b)
{
    if (!t)
        *a = *b = NULL;
    else if (t->key <= k)
    {
        *a = t;
        split(t->r, k, &(*a)->r, b);
        pull(*a);
    }
    else
    {
        *b = t;
        split(t->l, k, a, &(*b)->l);
        pull(*b);
    }
}

treap *newTreap(int k)
{
    treap *t = malloc(sizeof(treap));
    t->l = t->r = NULL;
    t->pri = rand();
    t->key = k;
    t->sz = 1;
    return t;
}

treap *insert(treap *t, int k)
{
    treap *a, *b;
    split(t, k, &a, &b);
    return merge(merge(a, newTreap(k)), b);
}

treap *erase(treap *t, int k)
{
    treap *a, *b, *c;
    split(t, k - 1, &a, &b);
    split(b, k, &b, &c);
    return merge(a, c);
}

int find_by_order(treap *t, int k)
{
    if (k < sz(t->l))
        return find_by_order(t->l, k);
    else if (k == sz(t->l))
        return t->key;
    return find_by_order(t->r, k - sz(t->l) - 1);
}

int main()
{
    int n, k, x = 0;
    scanf("%d%d", &n, &k);
    treap *root = NULL;
    for (int i = 1; i <= n; i++)
        root = insert(root, i);
    while (n)
    {
        x = (x + k) % n--;
        int y = find_by_order(root, x);
        printf("%d\n", y);
        root = erase(root, y);
    }
    return 0;
}
