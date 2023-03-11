class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        unsigned long long n = nums.size(), res = 0;
        sort(begin(nums), end(nums));
        for(int i = 0; i < n-1; ++i) {
            res += (upper_bound(begin(nums)+i+1, end(nums), upper-nums[i])-begin(nums)) -
                   (lower_bound(begin(nums)+i+1, end(nums), lower-nums[i])-begin(nums));
        }
        return res;
    }
};