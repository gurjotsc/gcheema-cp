class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> res(m, 1);
        for(int i = 0; i < m; ++i) {
            int a = queries[i][0], b = queries[i][1];
            while(a != b) {
                if(a < b) b /= 2;
                else a /= 2;
                ++res[i];
            }
        }
        return res;
    }
};