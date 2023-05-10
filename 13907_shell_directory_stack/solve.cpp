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
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
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

struct shell_dir_stk
{
    inline string parent() const { return pwd != "/" ? pwd.substr(0, pwd.find_last_of('/')) : ""; }

    string pwd = "/root", oldpwd = "/root";
    deque<string> dir;

    void cd(const string &path)
    {
        if (path == "-")
        {
            swap(pwd, oldpwd);
            return;
        }
        oldpwd = pwd;
        if (path.empty())
        {
            pwd = "/root";
            return;
        }
        if (path.substr(0, 2) == "..")
        {
            pwd = parent() + path.substr(2);
            if (pwd.empty())
                pwd.push_back('/');
            return;
        }
        switch (path.front())
        {
        case '.':
            if (pwd != "/")
                pwd += path.substr(1);
            else
            {
                pwd = path.substr(1);
                if (pwd.empty())
                    pwd.push_back('/');
            }
            break;
        case '~':
            pwd = "/root" + path.substr(1);
            break;
        case '/':
            pwd = path;
            break;
        default:
            pwd += '/' + path;
        }
    }

    bool pushd(const string &path)
    {
        if (path.empty())
        {
            if (dir.empty())
                return false;
            oldpwd = pwd;
            swap(pwd, dir.front());
            return true;
        }
        dir.push_front(pwd);
        cd(path);
        return true;
    }

    bool popd()
    {
        if (dir.empty())
            return false;
        oldpwd = exchange(pwd, dir.front());
        dir.pop_front();
        return true;
    }
};

int main()
{
    nevikw39;
    shell_dir_stk sds;
    string cmd;
    while (getline(cin, cmd))
    {
        stringstream ss(cmd);
        ss >> cmd;
        if (cmd == "cd")
        {
            string path;
            ss >> path;
            sds.cd(path);
            assert(sds.pwd.size());
        }
        else if (cmd == "pushd")
        {
            string path;
            ss >> path;
            if (!sds.pushd(path))
                cout << "pushd: no other directory\n";
            assert(sds.pwd.size());
        }
        else if (cmd == "popd")
        {
            if (!sds.popd())
                cout << "popd: directory stack empty\n";
        }
        else if (cmd == "pwd")
            cout << sds.pwd << '\n';
        else
        {
            cout << sds.pwd;
            for (const auto &i : sds.dir)
                cout << ' ' << i;
            cout << '\n';
        }
    }
    return 0;
}
