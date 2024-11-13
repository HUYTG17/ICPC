#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    IO;
    double a, n, m;
    cin >> a;
    for(double i = 1; i < 1000; ++i)
    {
        for(double j = 1; j < 1000; ++j)
        {
            if(i / j == a) 
            {
                n = i;
                m = j;
            }
        }
        if(n)
        {
            break;
        }
    }
    cout << n << '/' << m;
    return 0;
}