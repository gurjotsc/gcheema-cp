class Solution {
public:
    vector<vector<int>> dp;
    int ans = 0;
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(!m)
            return 0;
        int n = matrix[0].size();
        dp.assign(2, vector<int> (n + 1));
        for(int i = 1; i <= m; ++i) {
            int t = i % 2;
            for(int j = 1; j <= n; ++j) {
                if(matrix[i - 1][j - 1] == '0') dp[t][j] = 0;
                else {
                    dp[t][j] = dp[!t][j] + 1;
                }

                int minHeight = dp[t][j];
                for(int x = j; x >= 0; --x) {
                    int width = j - x + 1;
                    minHeight = min(minHeight, dp[t][x]);
                    ans = max(ans, minHeight * width);
                }
            }
        }
        return ans;
    }
};
