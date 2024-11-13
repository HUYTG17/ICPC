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

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;
        ll sum = 0;
        sum += (n - r) * (m + (n - r));
        cout << sum << ' ';
        if (c < m) {
            sum += (m - c) * 1; 
        }
        if (c > 1) {
            sum += (c - 1) * 1;
        }

        if(r <= c){
        sum += (r - 1) * m;
        }
        cout << sum << endl;
    }
    TGH;
}