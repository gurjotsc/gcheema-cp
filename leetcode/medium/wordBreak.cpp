class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        unordered_set wordDict(w.begin(), w.end());
        int n = s.size();
        if(!wordDict.size()) return false;
        vector<bool> dp(n+1); dp[0] = true;
        for(int i = 1; i <= n; ++i) { //iterate over dp
            for(int j = i-1; j >= 0; --j) { //iterate back over dp
                if(!dp[j]) continue;
                auto temp = s.substr(j, i-j); //(startPs, len)
                if(wordDict.count(temp)) {
                    dp[i] = true;
                    break; //move onto the next i because this one is in dicts
                }
            }
        }
        return dp.back();
        
    }
};