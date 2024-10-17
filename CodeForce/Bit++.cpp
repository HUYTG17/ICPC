#define ll long long
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
#define ifile freopen("inp.txt", "r", stdin)
#define ofile freopen("out.txt", "w", stdout)

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    TG; H;
    /*ifile;
    ofile;*/
    ll n, x = 0; 
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        if(s == "X++" || s == "++X")
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    cout << x;
    TGH;
}
