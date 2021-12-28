class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
    vector<vector<int>> seen; //stores the answer of a certain cell
    int m;
    int n;
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if(seen[i][j])
            return seen[i][j]; //if you've already been to this ceel, return its answer
        int ans = 1; //the minimum answer you can have for a cell is just 1 because there is at least the cell you are dfsing on
        for(auto d : dirs) {
            int x = i + d.first;
            int y = j + d.second;
            //bound check
            if(x < 0 || y < 0 || x >= m || y >= n) continue;
            if(matrix[x][y] <= matrix[i][j] || seen[x][y] == -1) continue;
            ans = max(ans, dfs(matrix, x, y) + 1); //return the max of what ans you have already seen before for a certain cell, and dfs of the matrix[x][y] + 1 (the +1 represents the answer of cell xy plus the current cell)
        }
        seen[i][j] = ans; //mark the current cell with its max
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        seen.resize(m, vector<int>(n, 0));
        int res = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, i, j)); //store the max dfs you can
            }
        }
        return res;
    }
};
