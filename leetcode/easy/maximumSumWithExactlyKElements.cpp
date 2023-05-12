class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = *max_element(begin(nums), end(nums));
        return(((mx+k-1)*(mx+k))/2)-((((mx-1)*(mx))/2));
    }
};