class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) res += ((nums[i] + nums[j]) == target);
        }
        for(int i = n-1; i >= 0; --i) {
            for (int j = i-1; j >= 0; --j) res += ((nums[i] + nums[j]) == target);
        }
        return res;
    }
}