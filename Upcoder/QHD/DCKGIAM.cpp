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
    vector<int> a(n);
    vector<int> L(n, 1);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    rep(i, 1, n)
    {
        rep(j, 0, i)
        {
            if(a[i] > a[j])
            {
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }
    cout << *max_element(L.begin(), L.end());
    TGH;
}

//or
/*
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
    vector<int> v(n);
    vector<int> a;
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    rep(i, 0, n)
    {
        auto it = lower_bound(a.begin(), a.end(), v[i]);
        if(it == a.end()) a.push_back(v[i]);  
        else *it = v[i];
    }
    cout << a.size();
    TGH;
}*/


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

    TGH;
}