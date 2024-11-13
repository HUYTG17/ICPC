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
    vector<int> v, v1;
    for(int i = 0; i < 2; ++i)
    {
        vector<int> v(3);
        for(int j = 0; i < 3; ++j)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
    }
    cout << (a[0] + a[1] == a[2] ? "yes" : "no") << '\n';
    TGH;
}

or
vector<int> v, v1;
    int x;
    for(int i = 0; i < 3; ++i)
    {
        cin >> x;
        v.push_back(x);
    }
    int y;
    for(int i = 0; i < 3; ++i)
    {
        cin >> y;
        v1.push_back(y);
    }
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    (v[0] + v[1] - v[2] == 0) ? cout << "yes\n" : cout << "no\n";
    (v1[0] + v1[1] - v1[2] == 0) ? cout << "yes\n" : cout << "no\n";