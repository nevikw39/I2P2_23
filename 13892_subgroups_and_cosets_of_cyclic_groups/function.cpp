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

#include <algorithm>

using namespace std;

/// ModularAdditiveGroup ///

// TODO:
// Helper method for public constructur
// Return the set based on N; i.e., {0, 1, ..., N-1}
set<int> ModularAdditiveGroup::construct_set(int x)
{
    set<int> y;
    generate_n(inserter(y, y.end()), x, [&]()
               { return y.size(); });
    return y;
}

// TODO:
// Implement addition of integers under modulus of N
int ModularAdditiveGroup::operator()(int lhs, int rhs) const { return (lhs + rhs) % N; }

// TODO:
// Generate the subgroup by a particular element
ModularAdditiveGroup *ModularAdditiveGroup::generate_subgroup(int g) const
{
    set<int> s;
    for (int i = g; !s.count(i); i = (*this)(i, g))
        s.insert(i);
    return new ModularAdditiveGroup(N, s);
}

/// PrimeModularMultiplicativeGroup ///

// TODO:
// Helper method for public constructur
// Return the set whose elements are coprime to n; since n is a prime here, it's {1, 2, ..., N-1}
set<int> PrimeModularMultiplicativeGroup::construct_set(int x)
{
    set<int> y;
    generate_n(inserter(y, y.end()), x - 1, [&]()
               { return y.size() + 1; });
    return y;
}

// TODO:
// Implement multiplication of integers under modulus of N
int PrimeModularMultiplicativeGroup::operator()(int lhs, int rhs) const { return 1LL * lhs * rhs % N; }

// TODO:
// Generate the subgroup by a particular element
PrimeModularMultiplicativeGroup *PrimeModularMultiplicativeGroup::generate_subgroup(int g) const
{
    set<int> s;
    for (int i = g; !s.count(i); i = (*this)(i, g))
        s.insert(i);
    return new PrimeModularMultiplicativeGroup(N, s);
}

/// Coset ///

// TODO:
// Construct the coset corresponding to g & H
set<int> coset(int g, const CyclicGroup *const H)
{
    set<int> y;
    for (int i : H->S)
        y.insert((*H)(i, g));
    return y;
}
