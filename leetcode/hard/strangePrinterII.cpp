class Solution {
public:
    int n, m;
    bool isPrintable(vector<vector<int>>& targetGrid) {
        n = targetGrid.size();
        m = targetGrid[0].size();
        vector<vector<int>> graph (61);
        vector<int> inDeg(61);
        
        for(int i = 1; i < 61; ++i) search(graph, targetGrid, inDeg, i);
        
        queue<int> q;
        unordered_set<int> seen;
        for(int i = 1; i <= 60; ++i) 
            if(!inDeg[i]) q.push(i);
        
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            seen.insert(curr);
            for(auto& child : graph[curr]) {
                inDeg[child]--;
                if(!inDeg[child]) q.push(child);
            }
        }
        
        
        return seen.size() == 61;
    }
    
    void search(vector<vector<int>>& graph, const vector<vector<int>>& targetGrid, vector<int>& inDeg, int color) {
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                if(targetGrid[i][j] == color) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, i);
                    maxY = max(maxY, i);
                }
            }
        
        if(minX == INT_MAX) return;
        
        for(int i = minX; i <= maxX; ++i)
            for(int j = minY; j <= maxY; ++j) {
                int interiorColor = targetGrid[i][j];
                if(interiorColor != color) {
                    graph[color].push_back(interiorColor);
                    ++inDeg[interiorColor];
                }
            }
    }
};