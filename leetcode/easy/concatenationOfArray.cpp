class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.insert(nums.end(), nums.begin(), nums.end()); //vector,insert(postion, iterator1, iterator 2)
        return nums;
    }
};
