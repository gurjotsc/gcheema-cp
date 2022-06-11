class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size(), m = sub.size();
        map<char, set<char>> changes;
        for(auto& i : mappings) changes[i[0]].insert(i[1]);
        for(int i = 0; i <= (n-m); ++i) {
            bool flag = true;
            for(int j = i, x = 0; x < m; ++j, ++x) {
                if(s[j] == sub[x]) continue;
                if(changes[sub[x]].count(s[j])) continue;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};