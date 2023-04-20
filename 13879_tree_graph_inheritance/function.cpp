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

#include <cassert>
#include <ctime>
#include <queue>
#include <random>
#include <algorithm>

using namespace std;

vector<int> graph::bfs(int source) const
{
    vector<int> d(n, numeric_limits<int>::max());
    d[source] = 0;
    queue<int> q;
    q.push(source);
    while (q.size())
    {
        source = q.front();
        q.pop();
        for (int i : adjacent_lists[source])
            if (d[i] > d[source] + 1)
            {
                assert(d[i] == numeric_limits<int>::max());
                d[i] = d[source] + 1;
                q.push(i);
            }
    }
    return d;
}

int tree::diameter() const
{
    static mt19937 mt(time(nullptr));
    static uniform_int_distribution uid(0, n - 1);
    vector<int> d0 = bfs(uid(mt)), d1 = bfs(max_element(d0.begin(), d0.end()) - d0.begin());
    return *max_element(d1.begin(), d1.end());
}
