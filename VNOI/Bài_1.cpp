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

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    fastIO;
    string s;
    int cnt = 0;
    cin >> s;
    string s1 = "virus";
        if(s.find(s1) != string::npos)
        {
            cnt++;
        }
    cout << cnt;
    TGH;
}