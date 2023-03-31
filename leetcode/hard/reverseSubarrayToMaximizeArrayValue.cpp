class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX, mx = INT_MIN;
        int initialSum = 0;
        int res;

        for(int i = 0; i < n-1; ++i) {
            initialSum += abs(nums[i]-nums[i+1]);
            mn = min(mn, max(nums[i], nums[i+1]));
            mx = max(mx, min(nums[i], nums[i+1]));
        }
        res = ((mx-mn)*2 >= 0) ? (mx-mn)*2 : 0;

        for(int i = 1; i < n-1; ++i) 
            res = max(res, abs(nums[0]-nums[i+1]) - abs(nums[i]-nums[i+1]));
        for(int i = 0; i < n-1; ++i) 
            res = max(res, abs(nums[n-1]-nums[i]) - abs(nums[i]-nums[i+1]));
        
        return initialSum+res;
    }
};