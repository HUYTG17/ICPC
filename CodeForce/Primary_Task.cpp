#define ll long long
#define TGH return 0
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

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
    /*ifile;
    ofile;*/
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        if(s.size() == 3 && s.substr(0, 2) == "10" && s.back() >= '2')
        {
            cout << "YES\n";
        }
        else if(s.size() > 3 && s.substr(0, 2) == "10" && s[2] != '0')
        {   
                cout << "YES\n";   
        }
        else
        {
            cout << "NO\n";
        }
    }
    TGH;
}