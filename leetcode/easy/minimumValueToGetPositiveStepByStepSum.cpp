class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 1, curr = 1;
        for(auto i : nums) {
            curr += i;
            if (curr < 1) {
                res += abs(curr - 1);
                curr = 1;
            }
        }
        return res;
    }
};