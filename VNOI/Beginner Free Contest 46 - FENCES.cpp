#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; i <= m; ++i)
    {
        sum += n;
    }
    for(int i = 0; i <= n; ++i)
    {
        sum += m;
    }
    cout << sum;
}


or  
int row, col;
cin >> row >> col;
cout << (row + 1) * col + (col + 1) * row;