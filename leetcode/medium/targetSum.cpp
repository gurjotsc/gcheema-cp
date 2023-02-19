class Solution {
public:
    int res;
    void recurse(const vector<int>& nums, const int& target, int sm = 0, int i = 0) {
        if(i >= nums.size()) {
             res += (sm == target);
             return;
        }
        recurse(nums, target, sm+nums[i], i+1);
        recurse(nums, target, sm-nums[i], i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        res = 0;
        recurse(nums, target);
        return res;
    }
};