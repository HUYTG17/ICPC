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
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, 0, n)
    {
        int num;
        cin >> num;
        mp[num]++;
    }
    //for(auto it : mp) cout << it.first << ' ' << it.second << '\n';
    /*
    1 3
    2 2
    3 1
    // 3 1 0
    */
    ll dem = 0;
    for(auto it : mp)
    {
        ll cnt = it.second;
        dem += cnt * (cnt - 1) / 2;
        //cout << dem << ' ';
    }
    cout << dem;
    TGH;
}


/*13 4 2
4 1 7 2 6 3 5 1 7 5 3 4 3*/
