class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res (n);
        int i = 0;
        int j = n-1;
        int idx = n-1;
        //two pointers. the middle element will be the smallest so bring two pointers on each side to the middle and keep on setting the elements in res (decrementing) to nums[pointer] squared
        while(idx >= 0) {
            if(abs(nums[i]) > abs(nums[j])) {
                res[idx] = nums[i] * nums[i];
                ++i;
            }
            else {
                res[idx] = nums[j] * nums[j];
                --j;
            }
            --idx;
        }
        return res;
    }
};
