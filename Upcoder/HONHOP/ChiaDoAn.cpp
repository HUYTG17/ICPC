#include <bits/stdc++.h>
#define ll long long
const int maxN = 2e5 + 7;
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, ans = 0;
    cin >> n;
    int a[maxN];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] += a[i - 1] - x; 
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        ans += abs(a[i] - a[n / 2]);
    }
    cout << ans;
    return 0;
}