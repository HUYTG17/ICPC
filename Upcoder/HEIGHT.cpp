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
    vector<int> v2 = v;
    sort(v2.begin(), v2.end());
    for(int i = 0; i < n; ++i)
    {
        int pos = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
        cout << pos << ' ';
    }
    return 0;
}