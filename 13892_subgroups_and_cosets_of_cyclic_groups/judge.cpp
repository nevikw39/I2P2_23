#include "function.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>

using std::cin;
using std::copy;
using std::cout;
using std::ostream_iterator;

int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(nullptr)->sync_with_stdio(false);
#endif // ONLINE_JUDGE
    ostream_iterator<int> ositr(cout, " ");

    int n0, g0, x0, n1, g1, x1;
    while (cin >> n0 >> g0 >> x0 >> n1 >> g1 >> x1)
    {
        CyclicGroup *mag = new ModularAdditiveGroup(n0);
        CyclicGroup *mag_s = mag->generate_subgroup(g0);
        assert(mag_s->S.count(mag_s->E));
        for (int i : mag_s->S)
            assert(mag_s->S.count(mag_s->inverse(i)) && (*mag_s)(i, mag_s->inverse(i)) == mag_s->E);
        auto cs = coset(x0, mag_s);
        copy(cs.begin(), cs.end(), ositr);
        cout << '\n';
        delete mag_s;
        delete mag;

        CyclicGroup *pmmg = new PrimeModularMultiplicativeGroup(n1);
        CyclicGroup *pmmg_s = pmmg->generate_subgroup(g1);
        assert(pmmg_s->S.count(pmmg_s->E));
        for (int i : pmmg_s->S)
            assert(pmmg_s->S.count(pmmg_s->inverse(i)) && (*pmmg_s)(i, pmmg_s->inverse(i)) == pmmg_s->E);
        cs = coset(x1, pmmg_s);
        copy(cs.begin(), cs.end(), ositr);
        cout << '\n';
        delete pmmg_s;
        delete pmmg;
    }
    return 0;
}
