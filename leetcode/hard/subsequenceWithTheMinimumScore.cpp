class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.size(), m = t.size();
        int res = 0;
        vector<int> suffixes(m, -1);
        int k = m-1;
        for(int i = n-1; i >= 0 && k >= 0; --i) if(s[i] == t[k])
            suffixes[k--] = i;
        res = k+1; //assume we remove everything up to k. This is the maximum possible score
        for(int i = 0, j = 0; i < n && j < m && res > 0; ++i) if(s[i] == t[j]) {
            while(k < m && suffixes[k] <= i) ++k;
            res = min(res, k-(j+1));
            ++j;
        }
        return res;
    }
};