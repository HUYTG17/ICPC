#define ll long long
#define TGH return 0
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
    vector<ll> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    ll sum = 0;
    ll Max = -maxN;
    ll profit = -maxN;
    for(int i = 0; i < n; ++i)
    {
        sum += v[i];
        Max = max(Max, v[i]);
        profit = max(profit, sum - Max);
        if(sum < 0)
        {
            sum = 0;
            Max = -maxN;
        }
        cout << sum << ' ' << Max << ' ' << profit << '\n';
    }
    cout << profit;
    TGH;
}