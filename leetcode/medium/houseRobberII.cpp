class Solution {
public:
    int n;
    int commence(vector<int>& nums, int l, int r) {
        int curr, prev;
        curr = prev = 0;
        for(int i = l; i <= r; ++i) {
            int temp = max(prev+nums[i], curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
    
    
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return nums[0];
        return max(commence(nums, 0, n-2), commence(nums, 1, n-1));
    }
};