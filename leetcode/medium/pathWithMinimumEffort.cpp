class Solution {
public:
    int r;
    int c;
    vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0, -1}};
    vector<vector<bool>> seen;

    void dfs(int i, int j, vector<vector<int>>& heights, int effort, int limit) {
        if(i == r - 1 && j == c - 1) throw effort;
        seen[i][j] = true;
        for (auto d:dirs) {
            int x = i + d.first;
            int y = j + d.second;
            if(x >= r || y >= c || x < 0 || y < 0 || seen[x][y]) continue;
            int newEffort = max(effort, abs(heights[x][y] - heights[i][j]));
            if(newEffort > limit) continue;
            dfs(x, y, heights, newEffort, limit);
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        r = heights.size();
        c = heights[0].size();
        int hi = 10e6;
        int lo = 0;
        while (lo < hi) {
            seen.assign(r, vector<bool>(c));
            int mid = lo + (hi - lo) / 2;
            seen[0][0] = true;
            try {
                dfs(0,0, heights, 0, mid);
                lo = mid + 1;
            }
            catch (int effort) {
                hi = effort;
            }
        }

        return lo;
    }
};
