#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

int main()
{
    fastIO;
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; ++i)
    {
        v.push_back(i);
    }
    do
    {
        for(int i = 0; i < n; ++i)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}