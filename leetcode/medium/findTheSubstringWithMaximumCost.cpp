class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();
        vector<int> v(26);
        iota(begin(v), end(v), 1);
        for(int i = 0; i < chars.size(); ++i) 
            v[chars[i]-'a'] = vals[i];

        int mn = 0, curr = 0, res = 0;
        for(int i = 0; i < n; ++i) {
            curr += (v[s[i]-'a']);
            res = max(res, curr-mn);
            mn = min(mn, curr);
        }

        return res;
    }
};