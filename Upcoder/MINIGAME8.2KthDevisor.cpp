#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> v;
    for(ll i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            v.push_back(i);
            if(i != n / i)
                v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    (k - 1 >= v.size()) ? cout << -1 : cout << v[k - 1];
    return 0;
}