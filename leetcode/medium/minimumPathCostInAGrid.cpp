class Solution {
public:
    int m, n;
    vector<vector<bool>> seen;
    int dfs(int i, int j, vector<vector<int>>& g, vector<vector<int>>& mc) {
        if(i == m-1) return g[i][j];
        if(seen[i][j]) return g[i][j];
        int mn = INT_MAX;
        int val = g[i][j];
        for(int x = 0; x < mc[val].size(); ++x) mn = min(mn, mc[val][x] + dfs(i+1, x, g, mc));
        g[i][j] += mn;
        seen[i][j] = true;
        return g[i][j];
    }
    int minPathCost(vector<vector<int>>& g, vector<vector<int>>& mc) {
        int res = INT_MAX;
        m = g.size(), n = g[0].size();
        seen.resize(m, vector<bool>(n, false));
        for(int j = 0; j < n; ++j) {
            g[0][j] = dfs(0, j, g, mc);
            res = min(res, g[0][j]);
        }
        return res;
    }
};