class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
    int maxLocal(vector<vector<int>>& g, int i, int j) {
        int mx = g[i][j];
        for(auto& d : dirs) 
            mx = max(mx, g[i+d.first][j+d.second]);
        return mx;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2));
        for(int i = 0; i < n-2; ++i)
            for(int j = 0; j < n-2; ++j)
                res[i][j] = maxLocal(grid, i+1, j+1);
        return res;
    }
};