#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    cin >> s;
    if(n >= 0 && n < s.length())
    {
        cout << s[n];
    }
    else
    {
        cout << -1;
    }
}
