class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0];
        int curMax = nums[0], curMin = nums[0];
        int total = nums[0];

        for(int i = 1; i < nums.size(); ++i)
        {
            curMax = max(nums[i], curMax + nums[i]);
            maxSum = max(maxSum, curMax);
            
            curMin = min(nums[i], curMin + nums[i]);
            minSum = min(minSum, curMin);
            total += nums[i];
        }
        if(total == minSum) return maxSum;
        return max(maxSum, total - minSum);
    }
};
