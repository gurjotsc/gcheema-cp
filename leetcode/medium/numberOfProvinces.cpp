class Solution {
public:
    unordered_set<int> visited;
    void dfs(vector<vector<int>>& isConnected, int i) {
        visited.insert(i);
        for(int j = 0; j < isConnected[i].size(); ++j) {
            if(j == i) continue;
            if(!isConnected[i][j] || visited.count(j)) continue;
            dfs(isConnected, j);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        visited.clear();
        int res = 0, n = isConnected.size();
        for(int i = 0; i < n; ++i) {
            if(!visited.count(i)) {
                ++res;
                dfs(isConnected, i);
            }
        }
        return res;
    }
};