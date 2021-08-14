class Solution {
public:
    vector<vector<int>> dp;
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        dp.assign(m + 1, vector<int> (n + 1));
        for(int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(matrix[i-1][j-1] == '0') dp[i][j] = 0;
                else {
                    int top = dp[i-1][j];
                    int diag = dp[i-1][j-1];
                    int left = dp[i][j-1];
                    dp[i][j] = min({top, diag, left}) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};
