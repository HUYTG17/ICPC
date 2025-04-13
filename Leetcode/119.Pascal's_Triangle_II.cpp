class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> dp(n + 1, 1);
        for(int i = 2; i <= n; ++i)
        {
            for(int j = i - 1; j > 0; --j)
            {
                dp[j] += dp[j - 1];
            }
        }
        return dp;
    }
};
