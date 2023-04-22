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
    int n[10] = {5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000}, p[10] = {-1, 11, 101, 181, 1181, 1811, 18181, 108881, 110881, 118081};
    for (int i = 1, t; i < 10; i++)
    {
        startTest(i);
        println(n[i], rnd.next(n[i]), rnd.next(n[i]), p[i], rnd.next(1, p[i] - 1), rnd.next(1, p[i] - 1));
    }
    return 0;
}
