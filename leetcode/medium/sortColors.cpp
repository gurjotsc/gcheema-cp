class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            int key = nums[i];
            for(int j = i - 1; j >= 0; --j) {
                if(key < nums[j]) {
                    nums[j + 1] = nums[j];
                    nums[j] = key;
                }
            }
        }
    }
};
