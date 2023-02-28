class Solution {
public:
    int n;
    int recurse(const vector<vector<int>>& g, vector<vector<int>>& dp, int i, int j) {
        if(i >= n || j >= n) return -1;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(i == n-1) return dp[i][j] = g[i][j];
        int res = INT_MAX;
        for(int x = 0; x < n; ++x) if(x != j)
            res = min(res, recurse(g, dp, i+1, x));
        return dp[i][j] = res+g[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dp(n, (vector<int>(n, INT_MAX)));
        int res = INT_MAX;
        for(int j = 0; j < n; ++j) res = min(res, recurse(grid, dp, 0, j));
        return res;
    }
};