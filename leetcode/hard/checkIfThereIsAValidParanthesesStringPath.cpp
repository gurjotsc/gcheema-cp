class Solution {
public:
    int m, n; 
    bool seen[100][100][201] = {false};
    bool dfs(vector<vector<char>>& grid, int i, int j, int l, int r) {
        if(i >= m || j >= n) return false;
        l += (grid[i][j] == '(');
        r += (grid[i][j] == ')');
        if(r > l) return false;
        int balance = l-r;
        if(seen[i][j][balance]) return false;
        seen[i][j][balance] = true;
        if(i == m-1 && j == n-1) return (l == r);
        return (dfs(grid, i+1, j, l, r) || dfs(grid, i, j+1, l, r));
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if(grid[0][0] == ')') return false;
        return dfs(grid, 0, 0, 0, 0);
    }
};