#define TG ios::sync_with_stdio(false)
#define H cin.tie(0)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    TG;
    H;
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    vector<int> v(m);
    for(int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        a.insert(price);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    for(int i = 0; i < m; i++)
    {
        auto it = a.upper_bound(v[i]);
        if(it == a.begin())
        {
            cout << -1 << '\n';
        }
        else 
        {
            --it;
            cout << *it << '\n';
            a.erase(it);
        }
    }
    return 0;
}