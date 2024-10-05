#define ll long long

#include <iostream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

ll a[100007];

int main()
{
    ll n, k; 
    cin >> n >> k;
    unordered_map<ll, ll> mp;
    unordered_set<ll> st;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int x = abs(k + a[i]);
        if(mp[x] == 1 && !st.count(x)) 
        {
            st.insert(x);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}