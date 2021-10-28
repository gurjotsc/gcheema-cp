class Solution {
public:
    //memoization solution
    //this means the solution is top-down and starts from the last index
    //in this problem we call from index 0 but nothing in dp gets updated until we reach the           last index which is dp[n] = 1
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        //store the last index as one so when we need to do res = mem(i+1), this will act as a             buffer
        dp[n] = 1;
        return memoization(0, s, dp);
    }
    int memoization(int i, string& s, vector<int>& dp) {
        if(dp[i] > 0) return dp[i]; //if you have completed dp on a spot just return the number                                       of ways you code decode a number from that index onward                                         (you have already solved the subproblem starting at this                                       string)
        if(s[i] == '0') return dp[i] = 0; //if a string (a subproblem in our case) starts from                                             0 that means it is invalid because a 0 doesn't map                                             to anything unless it comes after 1 or 2.
        //in this case you need to find the dp of the one after because you can always store             the next single digit value (unless its zerro but we have. a base case for that)
        int res = memoization(i+1, s, dp);
        //If its a '1' or '2' then see if the next digit is vlid (it always is for 1) and                 perform dp on i+2 because you are assuming you chose two digits here so you want to             "skip" the next dp at i+1 (the previous line of code will always cover this case)
        if(i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
            res += memoization(i+2, s, dp);
        }
        return dp[i] = res; //return whaetver the dp is at i
    }
};
