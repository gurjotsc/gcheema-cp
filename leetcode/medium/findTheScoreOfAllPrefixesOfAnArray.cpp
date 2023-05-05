class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n), conver(n);
        long long mx = nums[0], sm = nums[0]*2;
        res[0] = sm;
        conver[0] = mx*2;
        for(int i = 1; i < n; ++i) {
            mx = max(mx, (long long)nums[i]);
            conver[i] = nums[i]+mx;
            sm += conver[i];
            res[i] = sm;
        }
        return res;
    }
};