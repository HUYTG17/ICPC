#include <bits/stdc++.h>

const int INF = 1e9;

using namespace std;

int main()
{
    vector<int> coins = {1, 2, 5};
    int X;
    cin >> X;
    vector<int> dp(X + 1, 0);
    dp[0] = 1;
    for(int coin : coins)
    {
        for(int i = coin; i <= X; ++i)
        {
            dp[i] += dp[i - coin];
        }
    }
    cout << dp[X];
}
