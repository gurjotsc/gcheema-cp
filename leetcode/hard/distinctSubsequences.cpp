class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(m));
        //Backwards dp. Top down or some shit
        int cnt = m-1;
        for(int i = n-1; i >= 0; --i, --cnt){
            if(i == n-1) dp[i][m-1] += (s[n-1] == t[m-1]);
            else dp[i][m-1] = dp[i+1][m-1] + (s[i] == t[m-1]);
            for(int j = m-2; j >= max(0, cnt); --j) {
                if(s[i] == t[j] && i < n-1) {
                    if(s[i] == t[j+1]) dp[i][j] = dp[i+1][j] + (dp[i+1][j+1]);
                    else dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
                else 
                    dp[i][j] = (i < n-1) ? dp[i+1][j] : 0;
            }
        }
        return dp[0][0];
    }
};