class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int rows;
    int cols;
    int res;
    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i,j});
        grid[i][j] = -1;
        while(!q.empty()) {
            auto[x, y] = q.front(); q.pop();
            for(auto d : dirs) {
                int newX = x + d.first;
                int newY = y + d.second;
                //increment res when out of bounds
                if(newX >= rows || newY >= cols || newX < 0 || newY < 0) {
                    ++res;
                    continue;
                }
                //increment res when it hits water
                if(!grid[newX][newY]) {
                    ++res;
                    continue;
                }
                //continue if you've seen it before
                if(grid[newX][newY] == -1)
                    continue;
                q.push({newX, newY});
                //set to seen
                grid[newX][newY] = -1;
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        res = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] == 1) {
                    bfs(grid, i, j);
                    break;
                }
            }
        }
        return res;
    }
};
