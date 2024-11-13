#define ll long long
#define TGH return 0
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#include <iostream>
#include <fstream>
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
const int maxN = 2e5 + 7;
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    map<int, int> mp;
    int l(0);
    ll ans(0);
    rep(i, 0, n)
    {
        if(mp[v[i]])
        {
            while(mp[v[i]] > 0)
            {
                mp[v[l++]]--;
            }
        }
        mp[v[i]]++;
        ans += i - l + 1;
    }
    cout << ans << '\n';
}

int main() {
    fastIO;
    int T;
    cin >> T;
    while(T--)
        solve();
    TGH;
}