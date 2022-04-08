using ll = long long;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        if(!amount) return 0;
        if(coins[0] > amount) return -1;
        
        int n = coins.size();
        vector<ll> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        //for dp[i] it is 1 + the number of dp[i-c]
        //Take the minimum answer you find as you iterate through c for every i
        //we can iterate through all c since coins.size() is <= 12
        for(int i = 1; i <= amount; ++i)
            for(auto& c : coins)
                if(i - c >= 0) dp[i] = min(1+dp[i-c], dp[i]);

        //if you can't compute it then dp[amount] will be INT_MAX
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};