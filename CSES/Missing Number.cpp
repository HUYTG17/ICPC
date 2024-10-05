#define ll long long

#include <iostream>
#include <map>

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    map<ll, ll> mp;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(mp[i] != 1)
        {
            cout << i;
        }
    }
    return 0;
}

// 
/*int total = n * (n + 1) / 2;
int sum = 0;
for
sum += a[i];

int mis = total - sum;*/