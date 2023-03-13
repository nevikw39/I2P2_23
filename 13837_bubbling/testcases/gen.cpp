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

int main(int argc, char * argv[])
{
    registerGen(argc, argv, 1);
    int n[10] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 10000};
    for (int i = 1; i < 10; i++)
    {
        startTest(i);
        println(n[i]);
        vector<int> v(n[i]);
        for (int &j : v)
            j = rnd.next(INT_MIN, INT_MAX);
        println(v);
    }
    return 0;
}
