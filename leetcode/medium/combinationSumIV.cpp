class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> combs(target+1); //unsigned int because we know any cell that is > 32 bit int won't be used so we don't care if it overflows
        int n = nums.size();
        combs[0] = 1;
        for(int i = 1; i <= target; ++i)
            for(int j = 0; j < n; ++j)
                if((nums[j]) <= i) combs[i] += combs[i-nums[j]];
        return combs[target];
    }
};