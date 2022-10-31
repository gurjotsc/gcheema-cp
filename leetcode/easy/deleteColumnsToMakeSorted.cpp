class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int res = 0;
        for(int i = 0; i < m; ++i) {
            char prev = strs[0][i];
            for(auto j : strs) {
                if(j[i] < prev) {
                    ++res;
                    break;
                }
                else prev = j[i];
            }
        }
        return res;
    }
};