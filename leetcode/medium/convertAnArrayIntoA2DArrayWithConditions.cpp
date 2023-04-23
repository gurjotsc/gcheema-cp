class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        vector<int> cnt(n+1);
        
        for(auto& i : nums)
            mx = max(mx, ++cnt[i]);
        
        vector<vector<int>> res(mx);
        for(int i = 1; i <= n; ++i) {
            int j = 0;
            while(cnt[i]--)
                res[j++].push_back(i);
        }
        
        return res;

    }
};