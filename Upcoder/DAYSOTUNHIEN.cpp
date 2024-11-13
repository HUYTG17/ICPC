#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    vector<int> v;
    
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }    
    for(int i = 0; i < n - 1; ++i)
    {
        if(a[i + 1] - a[i] > 1)
        {
            for(int j = a[i] + 1; j < a[i + 1]; ++j)
            {
                v.push_back(j);
            }
        }
    }
    if(!v.empty())
    {
        cout << "Yes\n";
        for(auto it : v) cout << it;
    }
    else
    {
        cout << "No";
    }
    return 0;
}