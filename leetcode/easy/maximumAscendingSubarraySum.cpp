class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; ++i) {
            int sum = nums[i];
            for(int j = i+1; j < n; sum += nums[j++])
                if(nums[j] <= nums[j-1]) break;
            res = max(res, sum);
        }
        return res;
    }
};