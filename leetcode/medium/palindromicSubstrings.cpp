class Solution {
public:
    vector<vector<bool>> dp;
    int countSubstrings(string s) {
        int n = s.size();
        dp.assign(n, vector<bool> (n, false));
        int ans = 0;
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(i == j) dp[i][j] = true;
                else if(s[i] == s[j]) {
                    if(j - i == 1) {
                        dp[i][j] = true;
                    }
                    else if(dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
                if (dp[i][j]) ans++;
            }
        }
        return ans;
    }
};
