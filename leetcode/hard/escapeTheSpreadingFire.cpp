class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void bfsFire(vector<vector<int>>& f, vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) 
                if(grid[i][j] == 1) q.push({i,j});
        int depth = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front(); q.pop();
                for(auto d : dirs) {
                    int nr = curr[0] + d[0];
                    int nc = curr[1] + d[1];
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if(grid[nr][nc] == 2) continue;
                    if(f[curr[0]][curr[1]] != -1) continue;
                    q.push({nr, nc});
                }
                if(f[curr[0]][curr[1]] == -1) f[curr[0]][curr[1]] = depth;
            }
            depth++;
        }   
    }
    void bfsPerson(vector<vector<int>>& p, vector<vector<int>>& grid) {
        queue<vector<int>> q; q.push({0,0});
        int depth = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front(); q.pop();
                for(auto d : dirs) {
                    int nr = curr[0] + d[0];
                    int nc = curr[1] + d[1];
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if(grid[nr][nc] > 0) continue;
                    if(p[curr[0]][curr[1]] != -1) continue;
                    q.push({nr, nc});
                }
                if(p[curr[0]][curr[1]] == -1) p[curr[0]][curr[1]] = depth;
            }
            depth++;
        }   
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> person (m, vector<int> (n, -1));
        vector<vector<int>> fire (m, vector<int> (n, -1));
        
        bfsPerson(person, grid);
        bfsFire(fire, grid);
        
        if(person[m-1][n-1] == -1) return -1; //person can't reach there
        if(fire[m-1][n-1] == -1) return 1e9; //fire can't reach there
        if(fire[m-1][n-1] < person[m-1][n-1]) return -1; //fire reaches there before we can get there
        
        int diff = fire[m-1][n-1] - person[m-1][n-1]; //how many minutes after does the fire get there after the person
        //cells one to the left and one up from the bottom right
        int personLeft = person[m-1][n-2], personUp = person[m-2][n-1]; 
        int fireLeft = fire[m-1][n-2], fireUp = fire[m-2][n-1]; 
        
        if(personLeft > -1 && personUp > -1 && (fireLeft-personLeft > diff || fireUp-personUp > diff)) return diff;
        //if fireLeft/Up - personLeft/Up both are not greater than diff then that means at some point in any path the fire would be at the same cell as us so we need to start one minute early so we are one minute ahead of the fire
        return diff - 1;
        
    }
};