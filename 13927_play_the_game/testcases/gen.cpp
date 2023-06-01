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

using std::pair;
using std::vector;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n[] = {50, 100, 500, 1000, 5000, 10000, 50000, 100000, 100000, 100000};
    for (int i = 0; i < 10; i++)
    {
        startTest(i);
        vector<int> a(n[i]);
        for (int j = 0; j < n[i]; j++)
            if (rnd.wnext((n[i] + int(sqrt(j))) / int(sqrt(j) + 1), -sqrt(j)))
                a[j] = rnd.next(INT_MAX);
        println(n[i]);
        println(a);
    }
    return 0;
}
