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
#include <numeric>
#include <unordered_set>

using std::string;
using std::vector;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n[] = {100, 1000, 10000, 100000, 100, 1000, 10000, 100000, 100, 100000};
    for (int i = 0; i < 4; i++)
    {
        startTest(i);
        println(n[i]);
        vector<int> b(n[i]), g = rnd.perm(n[i], 1), w(n[i], 1);
        std::iota(b.begin(), b.end(), 1);
        println(b);
        println(g);
        println(w);
    }
    for (int i = 4; i < 8; i++)
    {
        startTest(i);
        println(n[i]);
        std::unordered_set<string> us;
        while (us.size() < n[i])
            us.insert(rnd.next("[a-zA-Z0-9]{1,10}"));
        vector<string> b(us.begin(), us.end()), g(us.begin(), us.end());
        shuffle(g.begin(), g.end());
        vector<int> w(n[i], 1);
        println(b);
        println(g);
        println(w);
    }
    for (int i = 8; i < 10; i++)
    {
        startTest(i);
        println(n[i]);
        std::unordered_set<string> us;
        while (us.size() < n[i])
            us.insert(rnd.next("[a-zA-Z0-9]{1,10}"));
        vector<string> b(us.begin(), us.end()), g(us.begin(), us.end());
        shuffle(g.begin(), g.end());
        vector<int> w(n[i]);
        for (int &i : w)
            i = rnd.next(1, int(1e6));
        println(b);
        println(g);
        println(w);
    }
    return 0;
}
