class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int m, n, res;
    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if(!grid2[i][j]) return false;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid2[i][j] = 0;
        bool notSub = false;
        //regular bfs
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            //flag when grid 2 does not meet sub island condition
            if(!grid1[x][y])
                    notSub = true;
            //we still want to perform bfs even if notSub == true since we need to set the entire island in grid2 to 0 (i.e mark it as seen) so we don't perform bfs on another part of the island
            for(auto d : dirs) {
                int newI = x + d.first;
                int newJ = y + d.second;
                if(newI >= m || newJ >= n || newI < 0 || newJ < 0 || !grid2[newI][newJ])
                    continue;
                q.push({newI, newJ});
                grid2[newI][newJ] = 0; //mark as seen
            }
        }
        return !notSub;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res += bfs(grid1, grid2, i, j);
            }
        }
        return res;
    }
};
