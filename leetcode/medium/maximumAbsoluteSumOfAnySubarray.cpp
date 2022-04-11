class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n);
        vector<int> dpMin(n);
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int res = abs(nums[0]);
        //No need for two dp arrays
        //Just store the min and max sum as you go and update res as you go
        for(int i = 1; i < n; ++i) {
            dpMax[i] = max(nums[i], nums[i] + dpMax[i-1]);
            dpMin[i] = min(nums[i], nums[i] + dpMin[i-1]);
            int currMax = max(dpMax[i], abs(dpMin[i]));
            res = max(res, currMax);
        }
        return res;
    }
};