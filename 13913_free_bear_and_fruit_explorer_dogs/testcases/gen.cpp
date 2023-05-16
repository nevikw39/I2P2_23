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
    for (int i = 0; i < 5; i++)
    {
        startTest(i);
        vector<int> a;
        while (a.size() < 100)
            for (int i = (a.size() ? a.back() : 0) + rnd.wnext(87, -69) + 1, n = rnd.wnext(10, -5); n--; i++)
                a.push_back(i);
        shuffle(a.begin(), a.end());
        println(a.size());
        println(a);
    }
    for (int i = 5; i < 10; i++)
    {
        startTest(i);
        vector<int> a;
        while (a.size() < 100000)
            for (int i : rnd.perm(rnd.wnext(50000, i == 5 ? 0 : 1000 * ((i & 1) - (~i & 1))), rnd.next(10000)))
                a.push_back(i);
        shuffle(a.begin(), a.end());
        println(a.size());
        println(a);
    }
    return 0;
}
