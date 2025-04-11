class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n);
        dp[0] = a[0];
        dp[1] = a[1];
        for(int i = 2; i < n; ++i)
        {
            dp[i] = a[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
