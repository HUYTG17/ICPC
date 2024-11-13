#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    int x;
    for(int i = 0; i < 5; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    int n, k;
    cin >> n >> k;
    if(n > 5) {
        cout << "null";
        return 0;
    }
    if(k < 0)
    {
        n += k + 1;
        k = -k;
    }
    for(int i = n; i < n + k; i++)
    {
        if(i >= 1 && i <= 5)
        {
            cout << v[i - 1] << ' ';
        }
    }
}