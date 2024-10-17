#define TG ios::sync_with_stdio(false)
#define H cin.tie(0)
#define ll long long

#include <bits/stdc++.h>

using namespace std;

int main() 
{
    TG; H;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> v1(n);
    vector<ll> v2(m);
    for(int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll i = 0, j = 0, cnt = 0;
    while(i < n && j < m)
    {
        if(v1[i] - k <= v2[j] && v1[i] + k >= v2[j]) 
        {
            cnt++;
            i++;
            j++;
        }
        else if(v1[i] - k > v2[j])
        {
            j++;
        }
        else if(v1[i] + k < v2[j])
        {
            i++;
        }
    }
    cout << cnt;
    return 0;
}