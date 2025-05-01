#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    if(n == 0 || n == 1) 
    {
        cout << 1;
        return 0;
    }
    if(n == 2)
    {
        cout << n;
        return 0;
    }
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}
