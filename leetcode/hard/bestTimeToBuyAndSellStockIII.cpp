class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //https://www.youtube.com/watch?v=oDhu5uGq_ic
        //It involves math not very logical to think about imo but the math checks out (prices[i]-prices[j]+dp[k-1][j-1])
        //                                                                        (dp[k-1][j-1]-prices[j]+prices[i])
        //                                                          maximize (dp[k-1][j-1]-prices[j], for j=0...i-1)
        //This is stored in max Diff as we don't need to recalculate the min of (dp[k-1][j-1]-prices[j]+prices[i]) by iterating over the array since each iteration we only have to look at one more new element so we can calculate it and store it as we go.
        int res = 0;
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n));
        for(int k = 1; k <= 2; ++k) {
            int mxDiff = dp[k-1][0]-prices[0];
            for(int i = 1; i < n; ++i) {
                dp[k][i] = max(dp[k][i-1], prices[i]+mxDiff);
                mxDiff = max(mxDiff, dp[k-1][i]-prices[i]); //in this line, our i "is" j now as were setting up mxDiff for the next iteration
            }
        }
        return dp[2][n-1];
    }
};