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

int main() {
    fastIO;
    int n, D, H;
    cin >> n >> D >> H;

    vector<int> h(n);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    vector<int> dp(n + 1, maxN);
    dp[1] = h[1];
    for (int i = 2; i <= n; ++i) {
        for (int j = max(1, i - D); j < i; ++j) {
            if (abs(h[i] - h[j]) <= H && dp[j] != maxN) { 
                int newHeight = dp[j] + h[i];
                dp[i] = min(dp[i], newHeight);
            }
        }
    }
    if (dp[n] == maxN) {
        cout << -1 << '\n'; 
    } else {
        cout << dp[n] << '\n';
    }
    TGH;
}
