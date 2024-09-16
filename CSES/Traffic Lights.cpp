#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)

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

int main() {
    TG; H;
    multiset<int> a, b;
    int q, n, x;
    cin >> q >> n;
    a.insert(0);
    a.insert(q);
    b.insert(q);
    for(int i = 0; i < n; i++) {
        cin >> x;
        auto vip = a.upper_bound(x);
        auto vt = vip;
        --vt;
        a.insert(x);
        auto er = b.find(*vip - *vt);
        b.erase(er);
        b.insert(*vip - x);
        b.insert(x - *vt);
        auto pos = b.end();
        cout << *(--pos) << " ";
    }
    TGH;
}

14