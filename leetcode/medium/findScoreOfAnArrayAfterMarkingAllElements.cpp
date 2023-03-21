class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> idxs(n);
        unordered_set<int> s;
        for(int i = 0; i < n; ++i) idxs[i] = i;
        stable_sort(begin(idxs), end(idxs), [&](auto a, auto b) {
            return nums[a] < nums[b];
        });
        sort(begin(nums), end(nums));
        long long score = 0ll;
        for(int i = 0; i < n; ++i) {
            if(!s.count(idxs[i])) {
                score += nums[i];
                s.insert(idxs[i]);
                s.insert(idxs[i]+1);
                s.insert(idxs[i]-1);
            }
        }
        return score;
    }
};