class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        return recur(w1, w2, n, m);;
    }

    int recur(const string& w1, const string& w2, int i, int j) {
        if(!i) return j;
        if(!j) return i;
        if(dp[i][j] != -1) return dp[i][j];

        if(w1[i-1] == w2[j-1]) return dp[i][j] = recur(w1, w2, i-1, j-1);

        int insert = recur(w1, w2, i, j-1);
        int del = recur(w1, w2, i-1, j);
        int replace = recur(w1, w2, i-1, j-1);
        return dp[i][j] = min(insert, min(del, replace))+1;
    }
};