class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> L(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                {
                    L[i] = max(L[i], L[j] + 1);
                }
            }
        }
        return *max_element(L.begin(), L.end());
    }
};
