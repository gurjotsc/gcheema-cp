class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        vector<int> dp(n-1);
        dp[0] = nums[0];
        for(int i = 1; i < n-1; ++i) {
            //you can't get to i
            if(dp[i-1] < i) return false;
            //so dp[i] will store the max of whats possible at that point
            //OR if there is a number in the past that will take you farther i+nums[i] then just store that because that number will allow you to do all of i+nums[i] plus more
            dp[i] = max(i+nums[i], dp[i-1]);
            if(dp[i] >= n-1) return true;
        }
        
        return dp[n-2] >= n-1;
          
    }
};