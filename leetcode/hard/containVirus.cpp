first find the all the islands of infected cells
for each island, calculate the max number of cells it can infect
store this in a vector along with the location the bfs began

marke off these islands with -1
build a wall around the most infectable island
pop from the vector (because it has a wall around it)
run thorugh the rest of the vector and simulate adding  cells
repeate steps ion this para




vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int m;
int n;
int bfsPossibleInfect(vector<vector<int>>& grid, int i, int j) {
    if(!grid[i][j]) return 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    int ans = 0;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        grid[x][y] = 0;
        for(auto d : dirs) {
            newX = x + d.first;
            newY = y + d.second;
            if(newX >= m || newY >= n || newX < 0 || newY < 0) continue;
            if(!grid[newX][newY]) {
                ++ans;
                continue;
            }
            q.push({newX, newY});
        }
        return -1*ans; //store -1 just in case ans is 1 so we don't confuse it with an infected cell
    }
}

int ans(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int res = 0;
    //double check that this actually sets the whole vector to be -1,-1
    vector<pair<int, int>> virality(m * n, -1); //bfsPossibleInfect cannot ever return an ans greater than m*n
    int days = 1;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j){
            //in the question it states that there will never be a tie, so no two grid[i][j] will be the same (other than 0 or 1)
            grid[i][j] = bfsPossibleInfect(grid, i, j);
            if(grid[i][j] < 0) {
                virality[grid[i][j] * -1].first = i;
                virality[grid[i][j] * -1].second = j;
            }
        }
    }
    for(int i = (m * n) - 1; i >= 0; --i) {
        if(virality[i].first == -1) continue;
        //you need some way to figure out how many infected cells will be in the future.
        //the problem with just using a days multipler is that, maybe in the future, you will hit a wall and it won't actually be as high as you calculate
        //maybe reperform bfs each time?
    }
    return res;
}
