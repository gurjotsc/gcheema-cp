class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(begin(nums), end(nums));
        int res = s.size();
        int i = 0;
        while(s.size()) {
            nums[i++] = *s.begin();
            s.erase(s.begin());
        }
        return res;
    }
};