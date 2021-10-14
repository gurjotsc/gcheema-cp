class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void dfs(int r, int c, vector<vector<char>>& grid) {
        //check bounds
        if(r > grid.size() - 1 || r < 0) return;
        if(c > grid[0].size() - 1 || c < 0) return;
        //if its not an island or we've already seen it
        if(grid[r][c] == '0') return;
        //if we made it here, grid[r][c] = 1, so now we make it 0 to symbolize that we have             "seen" this island
        grid[r][c] = '0';
        //look in every direction and dfs in that spot
        for(auto d : dirs) {
            int x = r + d.first;
            int y = c + d.second;
            dfs(x, y, grid);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        //dfs at every location
        //the reason we do it everywhere is because dfs doesn't extend out to every island so if there is more than one island, that means we haven't "seen" it yet
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') ans++; //if its a new island (we update grid in dfs)
                dfs(i, j, grid); //dfs at every spot
            }
        }
        return ans;
        //The key difference between bfs and dfs is that bfs looks at every node surrounding a point, and then explores those nodes, repating the same thing, while dfs finds a node, and then perfroms dfs there until moving on to the next node in dirs
    }
};
