#include <bits/stdc++.h>
#define ll long long
const int mode = 1e9 + 7;

using namespace std;

ll binpow(ll mu, ll n)
{
    ll s = 1;
    while(n)
    {
        if(n & 1)
            s = (s * mu) % mode;
        mu = (mu * mu) % mode;
        n /= 2;
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    cout << binpow(2, n) << '\n';
    return 0;
}