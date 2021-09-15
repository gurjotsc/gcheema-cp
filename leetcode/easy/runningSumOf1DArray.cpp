class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        //By not creating another vector and instead changing nums, we reduce space complexity to O(1) (no additional space used - we do not take into consideration the space occupied by the output array)
        //Iterate through the entire vector and change nums[i] to hold the running sum
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] = nums[i-1] + nums[i];
        }

        //Return nums
        return nums;
    }
};
