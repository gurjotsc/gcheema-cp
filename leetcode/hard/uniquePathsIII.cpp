class Solution {
public:
    int M, N, numEmpty;
    int dirs[4][2] = {{1,0}, {0,-1}, {-1, 0}, {0, 1}};
    vector<vector<bool>> seen;
    int ans = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY;
      M = grid.size();
      N = grid[0].size();
      seen.assign(M, vector<bool>(N));
      for(int i = 0; i < M; ++i) {
         for(int j = 0; j < N; ++j) {
             if(grid[i][j] == 1) {
                 startX = i;
                 startY = j;
             }
            if(grid[i][j] != -1) {
               ++numEmpty;
         }
             else seen[i][j] = true;

      }
    }
        dfs(grid, startX, startY, 1);
        return ans;
    }
   void dfs(vector<vector<int>>& grid, int x, int y, int length) {
      seen[x][y] = true;
      // printf("%d %d : %d\n", x, y, length);
      if (grid[x][y] == 2 && length == numEmpty) {
         ++ans;
         seen[x][y] = false;
          return;
      }

      for (auto& d : dirs) {
         int i = x + d[0];
         int j = y + d[1];

         if(i < M && i >= 0 && j < N && j >= 0 && !seen[i][j] ) {
            dfs(grid, i, j, length + 1);
         }

      }
      seen[x][y] = false;
   }
};
