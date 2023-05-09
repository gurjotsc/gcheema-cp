class Solution {
public:
    vector<int> res;
    vector<array<int, 2>> dirs{{0, 1}, {1,0}, {0,-1}, {-1,0}};
    int m, n;
    void dfs(vector<vector<int>>& mat, array<int, 2> prev = {-1, -1}, int i = 0, int j = 0) {
        res.push_back(mat[i][j]);
        mat[i][j] = -101;
        
        if(i+prev[0] >= 0 && j+prev[1] >= 0 && i+prev[0] < m && j+prev[1] < n)
            if(mat[i+prev[0]][j+prev[1]] != -101) {
                dfs(mat, prev, i+prev[0], j+prev[1]);
                return;
            }

        for(auto [x, y] : dirs) {
            if(i+x >= 0 && j+y >= 0 && i+x < m && j+y < n)
                if(mat[i+x][j+y] != -101) {
                    dfs(mat, {x, y}, i+x, j+y);
                    return;
                }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        res.clear();
        dfs(mat);
        return res;
    }
};