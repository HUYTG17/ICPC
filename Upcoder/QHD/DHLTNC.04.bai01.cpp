#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    vector<int> L;
    for(int i = 0; i < n; ++i)
    {
        auto it = lower_bound(L.begin(), L.end(), v[i]);
        if(it == L.end()) L.push_back(v[i]);
        else *it = v[i];
    }
    cout << L.size();
    return 0;
}