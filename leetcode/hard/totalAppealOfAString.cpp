using ll = long long;
class Solution {
public:
    long long appealSum(string s) {
        const ll n = s.size(); 
        array<ll, 26> cnt = {};
        ll dp = 0;
        ll res = 0;
        for(int i = 1; i <= n; ++i) {
            auto c = s[i-1];
            dp += (i-cnt[c-'a']);
            cnt[c-'a'] = i;
            res += dp;
        }
        return res;
    }
};