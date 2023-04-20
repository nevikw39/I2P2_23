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

#include "testlib.h"

using std::vector;
using std::pair;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n[10] = {5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};
    for (int i = 1, t; i < 10; i++)
    {
        startTest(i);
        t = rnd.next(INT_MAX);
        vector<int> p(n[i]);
        for (int i = 1; i < n[i]; i++)
            p[i] = rnd.wnext(i, t);
        vector<int> perm = rnd.perm(n[i]);
        vector<pair<int, int>> edges;
        for (int j = 1; j < n[i]; j++)
            if (rnd.next(2))
                edges.emplace_back(perm[j], perm[p[j]]);
            else
                edges.emplace_back(perm[p[j]], perm[j]);
        shuffle(edges.begin(), edges.end());
        println(n[i]);
        for (auto [a, b] : edges)
            println(a, b);
    }
    return 0;
}