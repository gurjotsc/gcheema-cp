class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return n;
        int l = 0, r = 1;
        int res = 1;
        while(r < n) {
            if(nums[r] > nums[r-1]) ++r;
            else {
                res = max(res, r-l);
                l = r;
                r++;
            }
        }
        return max(res, r-l);
    }
};