class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int T1 = text1.size();
        int T2 = text2.size();
        vector<vector<int>> dp (2, vector<int>(T2 + 1));
        for(int i = 1; i <= T1; ++i) {
            int t = i % 2;
            for(int j = 1; j <= T2; ++j) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[t][j] = dp[!t][j-1] +1;
                }
                else {
                    dp[t][j] = max(dp[!t][j], dp[t][j-1]);
                }
            }
        }

        return dp[T1 % 2][T2];
    }
};
