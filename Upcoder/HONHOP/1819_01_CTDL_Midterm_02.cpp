#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    vector<int> v;
    while(cin >> x)
    {
        bool flag = false;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] == x)
            {
                flag = true;
                continue;
            }
        }
        if(!flag)
        {
            v.push_back(x);   
        }
    }
    for(auto it : v) 
        cout << it << ' ';
    return 0;
}