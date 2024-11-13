#define ll long long
#define TGH return 0
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
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

struct Dog {
    int weight;
    int intelligence;
    int value;
};

bool compare(const Dog &a, const Dog &b) {
    if (a.weight == b.weight) {
        return a.intelligence >= b.intelligence;
    }
    return a.weight <= b.weight;
}

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<Dog> a(n);
    rep(i, 0, n) 
    {
        cin >> a[i].weight >> a[i].intelligence >> a[i].value;
    }
    sort(a.begin(), a.end(), compare);
    vector<ll> dp(n);
    rep(i, 0, n) 
    {
        dp[i] = a[i].value;
    }
    ll ans = 0;
    rep(i, 0, n) 
    {
        rep(j, 0, i) 
        {
            if (a[i].intelligence >= a[j].intelligence) {
                dp[i] = max(dp[i], dp[j] + a[i].value);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    TGH;
}