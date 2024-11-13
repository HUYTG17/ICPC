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

bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    fastIO;
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; ++i)
    {
        if(isPrime(i)) cout << i << '\n';
    }
    TGH;
}