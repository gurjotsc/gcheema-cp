class Solution {
public:
    int numSplits(string s) {
        unordered_map<int, int> m;
        unordered_map<int, int> l;
        int n = s.size(), sm = 0, lsm = 0, res = 0;
        for(auto i : s) {
            if(!m[i]) {++sm;}
            ++m[i];
        }
        for(int i = 0; i < n; ++i) {
            --m[s[i]];
            sm -= (!m[s[i]]);
            if(!l[s[i]]) ++lsm;
            ++l[s[i]];
            res += (lsm == sm);
        }

        return res;

    }
};