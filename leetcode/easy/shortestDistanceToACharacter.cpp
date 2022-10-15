class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, INT_MAX);
        
        for(int i = 0; i < n; ++i) {
            if (s[i] == c) {
                res[i] = 0;
                int l = i-1, r = i+1;
                while(l >= 0 && s[l] != c) {
                    res[l] = min(res[l], i-l);
                    l--;
                }
                while(r < n && s[r] != c) {
                    res[r] = min(res[r], r-i);
                    r++;
                }
            }
        }
        return res;
    }
};