class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>> res;
        map<int, vector<int>> m;
        int n = gs.size();
        for(int i = 0; i < n; ++i) {
            m[gs[i]].push_back(i);
            if (m[gs[i]].size() == gs[i]) {
                res.push_back(m[gs[i]]);
                m[gs[i]].clear();
            }
        }
        return res;
    }
};