class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        vector<int> dp;
        dp.push_back(nums[0]);
        if(nums.size() == 1) return ans;
        for(int i = 1; i < nums.size(); ++i) {
            if(dp[i-1] > 0) dp.push_back(nums[i] + dp[i-1]);
            else dp.push_back(nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
