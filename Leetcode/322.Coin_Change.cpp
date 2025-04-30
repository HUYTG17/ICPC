class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10000000);
        dp[0] = 0;
        for(int coin : coins)
        {
            for(int j = coin; j <= amount; ++j)
            {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
        return dp[amount] == 10000000 ? -1 : dp[amount];
    }
};
