class Solution {
public:
    void permuteRecursive(vector<int>& nums, vector<vector<int>>& ans, int i) {
        // base case
        if(i >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        //we start with the first index and swap it with each index after that (resetting after each swap so that each time we iterate we are only swapping two variables)
        //in each iteration we recursivley call permuteRecursive at the next index
        //this essentially means for each of the following indexes after each swap, we are going to do the same things for each permutation
        for(int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            permuteRecursive(nums, ans, i + 1);
            swap(nums[i],nums[j]); //reset it in nums
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; //ans vector
        permuteRecursive(nums, ans, 0); //start with the zeroth index
        return ans;
    }
};
