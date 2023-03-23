class Solution {
public:
    vector<array<int, 2>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[1][0] > 1 && grid[0][1] > 1) return -1;
        int m = grid.size(), n = grid[0].size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq; //we use greater because pq is implemented using vec.pop_back(). Since we want a min heap, we want the minimum element to be the last element in the vector.
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        while(!pq.empty()) {
            auto [time, row, col] = pq.top(); pq.pop();
            if(row == m-1 && col == n-1) return time;
            if(vis[row][col]) continue;
            vis[row][col] = true;

            for(auto& d : dirs) {
                int row2 = row+d[0], col2 = col+d[1];
                if(row2 < 0 || row2 >= m || col2 < 0 || col2 >= n) continue;

                if(grid[row2][col2] <= time+1) pq.push({time+1, row2, col2});
                else {
                    int wait = !((grid[row2][col2]-time)%2);
                    pq.push({grid[row2][col2]+wait, row2, col2});
                }
            }
        }
        return -1;
    }
};