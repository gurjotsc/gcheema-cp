class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        queue<pair<int, int>> q;
        //bfs at every location
        //the reason we do it everywhere is because bfs doesn't extend out of every island so if there is more than one island, that means we haven't "seen" it yet
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    ans++; //if its a new island , we increment ans
                    q.push({i, j}); //add it to the q to start out bfs of the new island
                    while(!q.empty()) { //iterate until we have been to every spot on the island
                        pair<int, int> temp = q.front(); //we need temp to explore that node
                        q.pop(); //pop temp since we are now going to explore that node
                        for(auto d : dirs) { //check every direction
                            int r = temp.first + d.first;
                            int c = temp.second + d.second;
                            //check bounds
                            if(r > grid.size() - 1 || r < 0) continue;
                            if(c > grid[0].size() - 1 || c < 0) continue;
                            //if its not an island
                            if(grid[r][c] == '0') continue;
                            //if we are still on the island, then push it to the q so we can                                 bfs at that node in the next iteration
                            q.push({r, c});
                            grid[r][c] = '0'; //marking that we have been to that node
                         }
                    }
                }
            }
        }
        return ans;
        //The key difference between bfs and dfs is that bfs looks at every node surrounding a point, and then explores those nodes, repating the same thing, while dfs finds a node, and then perfroms dfs there until moving on to the next node in dirs
    }
};
