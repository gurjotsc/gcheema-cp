class Solution {
public:
    vector<vector<int>> dp;
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        dp.assign(2, vector<int> (n + 1));
        for(int i = 1; i <= m; ++i) {
            int t = i % 2;
            for (int j = 1; j <= n; ++j) {
                if(matrix[i-1][j-1] == '0') dp[t][j] = 0;
                else {
                    int top = dp[!t][j];
                    int diag = dp[!t][j-1];
                    int left = dp[t][j-1];
                    dp[t][j] = min({top, diag, left}) + 1;
                }
                ans = max(ans, dp[t][j]);
            }
        }
        return ans*ans;
    }
};
