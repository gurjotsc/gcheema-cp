class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0,1}, {-1, 0}, {0,-1}};
    int m;
    int n;
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        //passes in the edge queues to start the bfs
        //iterate through dfs and mark each cell with true if its in bounds and if the cell is GREATER than or EQUAL to the cell being bfsed on.
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(auto d : dirs) {
                int i = x + d.first;
                int j = y + d.second;
                //if in bounds and greater than or equal, mark visited with true
                //if its already true then there is no need to repeat
                if(i >= 0 && j >= 0 && i < m && j < n && heights[i][j] >= heights[x][y] && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        m = heights.size();
        n = heights[0].size();
        //these two matricies store whether each cell can flow into the respective ocean
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        //bfs queus
        queue<pair<int, int>> p;
        queue<pair<int, int>> a;
        //each edge can flow into an ocean
        for(int i = 0; i < m; ++i) {
            //horizonal edges
            p.push({i, 0});
            a.push({i, n-1});
            pacific[i][0] = true;
            atlantic[i][n-1] = true;
        }
        for(int j = 0; j < n; ++j) {
            //vertical edges
            p.push({0, j});
            a.push({m-1, j});
            pacific[0][j] = true;
            atlantic[m-1][j] = true;
        }
        bfs(heights, p, pacific); //marks all cells that flow into the pacific with true
        bfs(heights, a, atlantic); //marks all cells that flow into the atlantic with true
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                //push back all cells that flow into both pacific and atlantic
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
}; 
