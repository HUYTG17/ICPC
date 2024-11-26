#include <bits/stdc++.h>

using namespace std;

bool check(char c)
{
    if(c == '>' || c == '<' || c == '=')
        return true;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        int a = s[0] - '0';
        int b = s[2] - '0';
        if(check(s[1]))
        {
            char c = s[1];
            if(c == '>' && a > b)
            {
                cout << a << c << b << '\n';
            }
            else if(c == '<' && a < b)
            {
                cout << a << c << b << '\n';
            }
            else if(c == '=' && a == b)
            {
                cout << a << c << b << '\n';
            }
            else if(c == '>' && a <= b)
            {
                cout << b + 1 << c << b << '\n';
            }
            else if(c == '<' && a >= b)
            {
                cout << 0 << c << b << '\n';
            }
            else if(c == '=' && a != b)
            {
                if(a > b)
                    cout << a << '>' << b << '\n';
                else
                    cout << a << '<' << b << '\n';
            }
        }
    }
}

//chua  accept