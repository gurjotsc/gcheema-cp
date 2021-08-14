class Solution {
public:
    vector<vector<int>> dp;
    int ans = 0;
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(!m)
            return 0;
        int n = matrix[0].size();
        dp.assign(m+1, vector<int> (n + 1));
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(matrix[i - 1][j - 1] == '0') dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }

                int minHeight = dp[i][j];
                for(int x = j; x >= 0; --x) {
                    int width = j - x + 1;
                    minHeight = min(minHeight, dp[i][x]);
                    ans = max(ans, minHeight * width);
                }
            }
        }
        return ans;
    }
};
