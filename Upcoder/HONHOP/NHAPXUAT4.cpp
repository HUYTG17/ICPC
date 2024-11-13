#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.size() < 3)
    {
        cout << -1;
        return 0;
    }
    cout << s[s.size() - 3];
}