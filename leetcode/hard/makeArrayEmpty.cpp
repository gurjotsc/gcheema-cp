class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        long long res = n;
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i) m[nums[i]] = i;
        sort(begin(nums), end(nums));
        for(int i = 1; i < n; ++i) if(m[nums[i]] < m[nums[i-1]])
            res += (n-i);
        return res;
    }
};