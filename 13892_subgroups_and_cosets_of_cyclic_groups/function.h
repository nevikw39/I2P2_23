#ifndef FUNCTION_H
#define FUNCTION_H

#include <cstdint>
#include <set>

using std::set;

class CyclicGroup
{
public:
    const set<int> S;                           // The set of elements
    virtual int operator()(int, int) const = 0; // The operation on set
    const int E;                                // The identity element
    virtual int inverse(int) const = 0;         // Return the inverse to a particular element

    CyclicGroup(const set<int> &s, int e) : S(s), E(e) {} // Note that const memeber must be initialized by initilizer list!!
    virtual ~CyclicGroup() = default;                     // It's important to declare destructor to be `virtual` in polymorphic class; otherwise delete would panic!!

    virtual CyclicGroup *generate_subgroup(int) const = 0; // Generate the subgroup by a particular element
};

class ModularAdditiveGroup : public CyclicGroup
{
private:
    static set<int> construct_set(int);                                         // TODO: Helper method for public constructur
                                                                                //       Return the set based on N; i.e., {0, 1, ..., N-1}
    ModularAdditiveGroup(int n, const set<int> &s) : N(n), CyclicGroup(s, 0) {} // This should be called by `generate_subgroup(int)`

public:
    int operator()(int, int) const override;                   // TODO: Implement addition of integers under modulus of N
    int inverse(int x) const override { return (-x + N) % N; } // Return the inverse to a particular element

    const int N;                                                            // The modulus
    ModularAdditiveGroup(int n) : N(n), CyclicGroup(construct_set(n), 0) {} // Create an additive group of integers modulo N

    ModularAdditiveGroup *generate_subgroup(int) const override; // TODO: Generate the subgroup by a particular element
                                                                 //       Since it's a polymorphic class, you should return something `new`ed!
};

class PrimeModularMultiplicativeGroup : public CyclicGroup
{
private:
    static set<int> construct_set(int);                                                    // TODO: Helper method for public constructur
                                                                                           //       Return the set whose elements are coprime to n; since n is a prime here, it's {1, 2, ..., N-1}
    PrimeModularMultiplicativeGroup(int n, const set<int> &s) : N(n), CyclicGroup(s, 1) {} // This should be called by `generate_subgroup(int)`

public:
    int operator()(int, int) const override; // TODO: Implement multiplication of integers under modulus of N
    int inverse(int x) const override        // Return the inverse to a particular element
    {                                        // x^{-1} \equiv x^{N-2} \mod N if N is a prime by Fermet's little theorem
        int64_t y = 1, a = x;                // Beware of overflow!!
        for (int i = N - 2; i; i >>= 1, (a *= a) %= N)
            if (i & 1)
                (y *= a) %= N;
        return y;
    }

    const int N;                                                                       // The modulus
    PrimeModularMultiplicativeGroup(int n) : N(n), CyclicGroup(construct_set(n), 1) {} // Create a multiplicative group of integers modulo N

    PrimeModularMultiplicativeGroup *generate_subgroup(int) const override; // TODO: Generate the subgroup by a particular element
                                                                            //       Since it's a polymorphic class, you should return something `new`ed!
};

/// Coset ///

set<int> coset(int, const CyclicGroup *const); // TODO: Construct the coset corresponding to g & H

#endif // FUNCTION_H

////////////////////////////////////////////////////////////////////////////////
//                              Separate Line!!!                              //
////////////////////////////////////////////////////////////////////////////////

/**
 *
 * It's recommended that you should implement the functions in a different file.
 *
 * If you edit `function.h` directly, don't paste the codes above.
 *
 */

// Starter codes are provided below. Uncomment them and begin coding!

/**

/// ModularAdditiveGroup ///

// TODO:
// Helper method for public constructur
// Return the set based on N; i.e., {0, 1, ..., N-1}
set<int> ModularAdditiveGroup::construct_set(int x)
{
    // ...
}

// TODO:
// Implement addition of integers under modulus of N
int ModularAdditiveGroup::operator()(int lhs, int rhs) const
{
    // ...
}

// TODO:
// Generate the subgroup by a particular element
ModularAdditiveGroup *ModularAdditiveGroup::generate_subgroup(int g) const
{
    // ...
    return new // ...
}

/// PrimeModularMultiplicativeGroup ///

// TODO:
// Helper method for public constructur
// Return the set whose elements are coprime to n; since n is a prime here, it's {1, 2, ..., N-1}
set<int> PrimeModularMultiplicativeGroup::construct_set(int x)
{
    // ...
}

// TODO:
// Implement multiplication of integers under modulus of N
int PrimeModularMultiplicativeGroup::operator()(int lhs, int rhs) const
{
    // ...
}

// TODO:
// Generate the subgroup by a particular element
PrimeModularMultiplicativeGroup *PrimeModularMultiplicativeGroup::generate_subgroup(int g) const
{
    // ...
    return new // ...;
}

/// Coset ///

// TODO:
// Construct the coset corresponding to g & H
set<int> coset(int g, const CyclicGroup *const H)
{
    // ...
}

 */
