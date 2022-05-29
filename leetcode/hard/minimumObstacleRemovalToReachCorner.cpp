class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<array<int, 3>> q;
        q.push({0, 0, 0});
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!q.empty()) {
            auto curr = q.top(); q.pop();
            if(-curr[0] != dist[curr[1]][curr[2]]) continue;
            for(auto& d : dirs) {
                int x = curr[1] + d[0];
                int y = curr[2] + d[1];
                if(x >= m || y >= n || x < 0 || y < 0) continue;
                int c = grid[x][y] - curr[0];
                if(c < dist[x][y]) {
                    dist[x][y] = c;
                    q.push({-c, x, y});
                }
            }
        }
        return dist[m-1][n-1];
    }
};