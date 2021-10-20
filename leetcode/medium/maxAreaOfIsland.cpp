class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0, -1}}; //all possible directions

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        //base cases
        if(m == 1 && n == 1) {
            if(grid[0][0]) return 1;
            else return 0;
        }
        queue<pair<int, int>> q;
        //iterate through entire grid
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                int area = 0; //declare area
                //if the the cell we are one is an island, then we push that to our bfs q and                   increase area by 1
                if(grid[r][c] == 1) {
                    ++area;
                    q.push({r, c});
                    grid[r][c] = 0;
                }
                //continue bfs until the q is empty (in other words until you have complete                     bfs on the island)
                while(!q.empty()) {
                    auto [row, column] = q.front(); q.pop(); //structure binding
                    //iterate through four directions
                    for(auto d : dirs) {
                        //update coordinates
                        int y = row + d.first;
                        int x = column + d.second;
                        //if out of bounds then continue
                        if(y >= m || y < 0 || x >= n || x < 0) continue;
                        //if the grid is == 1 then update the area and push it to the queue
                        if(grid[y][x] == 1) {
                            ++area;
                            q.push({y,x});
                            grid[y][x] = 0; // update grid as we have now "seen" this cell
                        }
                    }
                }
                ans = max(ans, area); //update ans to be the greater area
            }
        }
        return ans;
    }
};
