#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
const int maxN = 2e5 + 7;

#include <bits/stdc++.h>

using namespace std;

int main()
{
    IO;
    ll n, ans = 0;
    cin >> n;
    ll a[maxN];
    for(ll i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(ll i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        a[i] += a[i - 1]  - x;
    }
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; ++i)
    {
        ans += abs(a[i] - a[(n + 1) / 2]);
    }
    cout << ans;
    return 0;
}