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

string solve(int n) {
    if (n == 1 || n == 3) {
        return "-1";  
    } else if (n == 2) {
        return "66";   
    } else if (n == 4) {
        return "3366"; 
    } else {
        string s;
        if (n % 2 == 0) {
            s = "3366";  
            s.insert(0, n - 4, '3');
        } else {
            s = "36366"; 
            s.insert(0, n - 5, '3');
        }
        return s; 
    }
}
 
int main() {
    fastIO;
    int t;
    cin >> t; 
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n; 
        cout << solve(n) << endl; 
    }
    TGH;
}

