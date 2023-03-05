class Solution {
using ull = unsigned long long;
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        ull mod = 1e9+7;
        vector<ull> dp(target+1);
        dp[0] = 1;
        for(auto t : types)
            for(int i = target; i >= 1; --i)
                for(int k = 1; k <= t[0] && (i-(t[1]*k)) >= 0; ++k) {
                    dp[i] += dp[i-(t[1]*k)];
                    dp[i] %= mod;
                }
        return dp[target];
    }
};