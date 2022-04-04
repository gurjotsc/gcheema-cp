class Solution {
public:
    using ll = long long;
    ll numberOfWays(string s) {
        ll n = s.size();
        ll cnt0 = 0, cnt1 = 0;
        ll cnt01 = 0, cnt10 = 0;
        ll cnt010 = 0, cnt101 = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '0') {
                cnt0++;
                cnt10 += cnt1;
                cnt010 += cnt01;
            }
            else if(s[i] == '1') {
                cnt1++;
                cnt01 += cnt0;
                cnt101 += cnt10;
            }
        }
        
        return cnt010 + cnt101;
    }
};