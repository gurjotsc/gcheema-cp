class Solution {
public:
    int maxScore(vector<int>& nums) {
        long long res = 0, pre = 0;
        sort(begin(nums), end(nums), greater<>());
        for(int& i : nums) {
            pre += i;
            res += (pre > 0);
        }
        return res;
    }
};