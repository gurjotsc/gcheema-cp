class Solution {
public:
    int n;
    vector<long long> dp; //going to act as an lru cache
    int dfs(const string& s, const int& k, const int& i) {
        if(i == n) return 1; //base case after n-1 since theres only 1 way to store a single character
        if(s[i] == '0') return 0;
        if(dp[i] > -1) return dp[i]; //the number of ways that you can restore the array if the problem was s[i...n-1]

        long long res = 0;
        long long curr = 0; //s[i...j]
        for(int j = i; j < n; ++j) {
            curr = (curr*10) + (s[j]-'0');
            if(curr > k) break;
            res += (dfs(s, k, j+1)); //start the next substring at j+1
            res %= (long long)(1e9)+7;
        }
        return dp[i] = res;
    }
    int numberOfArrays(string s, int k) {
        n = s.size();
        dp.clear();
        dp.resize(n,-1);
        return dfs(s, k, 0);
    }
};