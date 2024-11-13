#define ll long long
#define TGH return 0
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ifile freopen("inp.txt", "r", stdin)
#define ofile freopen("out.txt", "w", stdout)
const int maxN = 2e5 + 7;
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

ll f[maxN], a[maxN], n, S;

int main() {
    fastIO;
    ifstream in("COINS.INP");
    ofstream out("COINS.OUT");
    in >> n >> S;
    rep1(i, 1, n)
    {
        in >> a[i];
    }
    rep1(i, 1, S)
    {
        f[i] = -1;
    }
    rep1(i, 1, S)
    {
        rep1(j, 1, n)
        {
            if(a[j] <= i && f[i - a[j]] != -1)
            {
                if(f[i] != -1)
                {
                    f[i] = min(f[i], f[i - a[j]] + 1);
                }
                else
                {
                    f[i] = f[i - a[j]] + 1;
                }
            }
        }
    }
    out << f[S];
    TGH;
}