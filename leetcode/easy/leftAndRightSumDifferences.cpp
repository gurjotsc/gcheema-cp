class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        int l = accumulate(begin(nums), end(nums), 0);
        int r = 0;
        for(int i = n-1; i >= 0; --i) {
            int temp = nums[i];
            l -= nums[i];
            nums[i] = abs(l - r);
            r += temp;
        }
        return nums;
    }
};