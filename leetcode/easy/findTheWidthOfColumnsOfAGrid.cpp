class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);
        function<int(int)> check = [&](int j) {
            int ans = 0;
            for(int i = 0; i < m; ++i) {
                int curr = 0;
                if(!grid[i][j]) {
                    ans = max(ans, 1);
                    continue;
                }
                while(grid[i][j]) {
                    if(grid[i][j] < 0) {
                        ++curr;
                        grid[i][j] *= -1;
                        continue;
                    }
                    grid[i][j] /= 10;
                    ++curr;
                }
                ans = max(ans, curr);
            }
            return ans;
        };

        for(int j = 0; j < n; ++j) res[j] = check(j);
        return res;
    }
};