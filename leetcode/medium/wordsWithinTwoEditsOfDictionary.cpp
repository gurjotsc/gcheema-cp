class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        int n = queries[0].size();
        for(auto q : queries) {
            int diff;
            for(auto w : dictionary) {
                diff = 0;
                for(int i = 0; i < n; ++i) diff += (w[i] != q[i]);
                if(diff <= 2) break;
            }
            if(diff <= 2) res.push_back(q);
        }
        return res;
    }
};