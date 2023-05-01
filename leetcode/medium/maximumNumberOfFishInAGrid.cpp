class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0, curr = 0;
        vector<array<int, 2>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        function<void(int, int)> dfs = [&](int r, int c) {
            if(r < 0 || r >= m || c < 0 || c >= n) return;
            if(!grid[r][c]) return;
            curr += grid[r][c];
            grid[r][c] = 0;
            for(auto& d : dirs)
                dfs(r+d[0], c+d[1]);
        };

        for(int r = 0; r < m; ++r)
            for(int c = 0; c < n; ++c) {
                dfs(r, c);
                res = max(res, curr);
                curr = 0;
            }
        
        return res;
    }
};