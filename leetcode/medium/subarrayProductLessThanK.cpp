class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(!k) return 0;
        int ans = 0;
        int product = 1;
        for(int i = 0, j = 0; j < nums.size(); ++j) {
            product *= nums[j];
            while(i <= j && product >= k) {
                product /= nums[i++];
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
