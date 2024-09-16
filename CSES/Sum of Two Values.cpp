#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)
#define ll long long


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

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

ll n, x, a;
int main() {
    TG; H;
    cin >> n >> x;
    map<ll, ll> mp;
    /*if(n <= 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }*/
    for(int i = 1; i <= n; i++) {  // for i thì ko liên quan các phần tử trong map chưa sắp xếp
        cin >> a;
        if(mp[a] == 0) mp[a] = i;
        if((mp[x - a] > 0) && (mp[x - a] != i)) {
            cout << mp[x - a] << " " << i;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    TGH;
}
