Cho dãy gồm n số nguyên hãy tìm dãy con giảm dài nhất. Dãy con giảm có nghĩa là phần tử đứng sau phải bé hơn phần tử đứng trước.
Input:
- Dòng 1: một số nguyên dương n (1 <= n <= 1000).
- Dòng 2: n số nguyên ai (|a| <= 109).
Output:
Một số duy nhất là độ dài của dãy con giảm dài nhất.
Ví dụ:

Input

Output

8

8 3 4 6 4 5 2 1

5



Giải thích: Dãy giảm dài nhất là 8 6 5 2 1. 

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
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    vector<int> L(n, 1);
    rep(i, 1, n)
    {
        rep(j, 0, i)
        {
            if(v[i] < v[j])
            {
                L[i] = max(L[i], L[j] + 1);
                //cout << i << ' ' << j << ' ' << L[j] << ' ' << L[i] << '\n';
            }
        }
        //cout << '\n';
    }
    cout << *max_element(L.begin(), L.end());
    TGH;
}


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