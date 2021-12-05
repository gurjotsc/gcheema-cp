class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i+1] <= nums[i]) {
                res += nums[i] + 1 - nums[i+1];
                nums[i+1] = nums[i] + 1;
            }
        }
        return res;
    }
};
