class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLength = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int currCount = 0;
            for(int j = i; nums[j] >= 0; ++currCount) {
                int temp = nums[j];
                nums[j] = -1;
                j = temp;
            }
            maxLength = max(maxLength, currCount);
        }
        return maxLength;
    }
};
