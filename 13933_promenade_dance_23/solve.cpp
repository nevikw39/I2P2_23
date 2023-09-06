/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

struct bit_max // Binary Indexed Tree (Frenwick Tree) that is on the binary operation ``max''
{
    int n;
    vector<int> v;
    bit_max(int _n) : n(_n), v(n + 1) {}
    static int lowbit(int x) { return x & -x; }
    int query(int x)
    {
        int y = 0;
        for (; x; x -= lowbit(x))
            y = max(y, v[x]);
        return y;
    }
    int query() { return query(n); }
    void update(int x, int val = 1)
    {
        val += query(x - 1);
        for (; x <= n; x += lowbit(x))
            v[x] = max(v[x], val);
    }
};

int main()
{
    nevikw39;
    int n;
    cin >> n;
    _hash<string, int> hm;
    for (int i = 1; i <= n; i++)
    {
        string b;
        cin >> b;
        hm[b] = i;
    }
    vector<int> v;
    v.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        string g;
        cin >> g;
        v.push_back(hm[g]);
    }
    bit_max fenwick_tree_weighted_lis(n);
    for (int i : v)
    {
        int w;
        cin >> w;
        fenwick_tree_weighted_lis.update(i, w);
    }
    cout << fenwick_tree_weighted_lis.query() << '\n';
    return 0;
}
