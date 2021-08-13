class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j, string& s) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(s[i] == s[j]) dp[i][j] = 2 + dfs(i + 1, j - 1, s);
        else dp[i][j] = max(dfs(i, j - 1, s), dfs(i + 1, j, s));
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size() ;
        dp.assign(n, vector(n, -1));
        return dfs(0, n - 1, s);
    }
};
