class Solution {
public:
    vector<pair<int, int>> dirs = {{-2,-1}, {-1, -2}, {-2, 1}, {1, -2}, {2, -1}, {-1, 2}, {2, 1}, {1, 2}};
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]) return false;
        int n = grid.size();
        pair<int, int> curr = {0,0};
        for(int i = 1; i < n*n; ++i) {
            bool flag = false;
            for(auto [x, y] : dirs) {
                int ii = curr.first + x;
                int jj = curr.second + y;
                if(ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
                if(grid[ii][jj] != i) continue;
                flag = true;
                curr = {ii, jj};
                break;
            }
            if(!flag) return false;
        }
        return true;
    }
};