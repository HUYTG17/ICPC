#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> v;
    while(n--)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int q;
    cin >> q;
    while(q--)
    {
        string str;
        cin >> str;
        int cnt = 0;
        for(auto it : v)
        {
            if(str == it)
                cnt++;
        }
        cout << cnt << '\n';
    }
}