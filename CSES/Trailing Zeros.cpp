#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, ans = 0; 
    cin >> n;
    for(int i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    cout << ans;
    return 0;
}