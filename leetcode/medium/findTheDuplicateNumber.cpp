class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //Actual solution that fits constraints
        // sort(nums.begin(), nums.end());
        // for(int i = 1; i < nums.size(); ++i)
        //     if(nums[i] == nums[i-1]) return nums[i];
        
        
        //modify the array solution
        for(auto& i : nums)
            if(nums[abs(i)] > 0) nums[abs(i)] *= -1;
            else return abs(i);
        
        
        return -1;
    }
};