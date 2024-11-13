#define ll long long
#define TGH return 0
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#include <iostream>
#include <iomanip>
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
const int maxN = 2e9 + 7;
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    fastIO;
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> v;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    rep(i, 0, n)
    {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if(it == v.end()) v.push_back(a[i]);
        else *it = a[i];
    }
    cout << v.size();
    TGH;
}
