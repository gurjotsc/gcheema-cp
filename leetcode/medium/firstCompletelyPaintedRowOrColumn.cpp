class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int k = arr.size();
        vector<pair<int, int>> coords((m*n)+1);
        vector<int> rows(m, n), cols(n, m);
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                coords[mat[i][j]] = {i, j};
        
        for(int i = 0; i < k; ++i) {
            auto [r, c] = coords[arr[i]];
            --rows[r]; --cols[c];
            if(!rows[r] || !cols[c])
                return i;
        }

        return -1;
    }
};