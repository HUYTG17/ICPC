#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        s += a[i][i];
        s += a[i][n - 1 - i];
    }
    cout << s;
}