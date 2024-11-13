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
const int maxN = 6e5 + 7;
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    fastIO;
    int n, h, x, a[maxN];
    cin >> n >> h;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x;
        if(i % 2)
        {
            a[1]++;
            a[x + 1]--;
        }
        else
        {
            a[h - x + 1]++;
        }
    }
    int ans = maxN, cnt = 0;
    for(int i = 1; i <= h; ++i)
    {
        a[i] += a[i - 1];
        if(a[i] < ans)
        {
            ans = a[i];
            cnt = 1;
        }
        else
        {
            cnt += (a[i] == ans);
        }
    }
    cout << ans << ' ' << cnt;
    TGH;
}