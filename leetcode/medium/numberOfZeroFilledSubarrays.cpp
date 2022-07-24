class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i]) continue;
            long long sz = 0;
            while(i < n && !nums[i]) {
                res += (++sz);
                ++i;
            }
        }
        return res;
    }
};