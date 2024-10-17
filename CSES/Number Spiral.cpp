#include <bits/stdc++.h>
#define lli long long int

using namespace std;

lli findNumber(lli y, lli x)
{
    lli n = max(y, x);
    if(n % 2) return pow(n, 2) - (y - 1) + (n - x);
    return pow(n - 1, 2) + 1 + (y - 1) + (n - x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    lli n;
    cin >> n;
    while(n--)
    {
        lli y, x;
        cin >> y >> x;
        cout << findNumber(y, x) << '\n';
    }
    return 0;
}