class Solution {
public:
    string recurse(const vector<int>& cost, vector<vector<string>>& dp, int target, int idx) {
        if(!target) return "";
        if(target < 0 || idx >= 9) return "0";

        if(dp[idx][target] != "-1") return dp[idx][target];

        string take = to_string(idx+1) + recurse(cost, dp, target-cost[idx], 0);
        string skip = recurse(cost, dp, target, idx+1);

        return dp[idx][target]=getBigger(take, skip);
    }

    string getBigger(const string& s1, const string& s2) {
        if(s1.find("0") != string::npos) return s2;
        if(s2.find("0") != string::npos) return s1;
        return (s1.size() > s2.size()) ? s1 : s2;
    }

    string largestNumber(vector<int>& cost, int target) {
        if(*min_element(begin(cost), end(cost)) > target) return "0";
        vector<vector<string>> dp(10, vector<string>(target+1, "-1"));
        return recurse(cost, dp, target, 0);
    }
};