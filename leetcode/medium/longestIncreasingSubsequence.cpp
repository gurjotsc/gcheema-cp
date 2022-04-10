class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); //stores max subsequence at a point
        int res = 1;
        for(int i = n-1; i >= 0; --i) {
            int mxLength = 1;
            for(int j = i+1; j < n; ++j)
                //if you can add nums[i] to the j'th subsequence
                if(nums[i] < nums[j]) mxLength = max(mxLength, dp[j]+1);
            dp[i] = mxLength;
            res = max(res, dp[i]);
        }
        return res;
    }
};