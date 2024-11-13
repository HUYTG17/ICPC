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
    int n;
    cin >> n;
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            int x;
            cin >> x;
            sum += x;
        }
        if(sum >= 2)
        {
            cnt++;
        }
        sum = 0;
    }
    cout << cnt;
    TGH;
}