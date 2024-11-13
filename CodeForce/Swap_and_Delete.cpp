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
        int cnt1(0), cnt2(0);
        for(int i = 0;  i < s.size(); ++i)
        {
            if(s[i] == '0') ++cnt1;
            else ++cnt2;
        }
        int tmp = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '1' && cnt1 > 0) --cnt1;
            else if(s[i] == '0' && cnt2 > 0) --cnt2;
            else 
            {
                tmp = s.size() - i; 
                break;
            }
        }
        cout << tmp << '\n';
    }
    TGH;
}