class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        sort(begin(nums), end(nums));
        int curr = 0;
        vector<int> res;
        for(int i = n-1; i >= 0; --i) {
            sum -= nums[i];
            curr += nums[i];
            res.push_back(nums[i]);
            if(curr > sum || i == 0) return res;
        }
        return {};
    }
};