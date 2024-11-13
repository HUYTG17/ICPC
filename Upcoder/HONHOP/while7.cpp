#include <bits/stdc++.h>

using namespace std;

void solve(string s)
{
    int sum = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        int digit = s[i] - '0';
        if(digit % 2 == 1)
        {
            sum += digit;
        }
    }
    cout << sum;
}

int main()
{
    string s;
    cin >> s;
    solve(s);
}