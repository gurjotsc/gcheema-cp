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
        for(int i = 0; i <= 60; ++i) 
            if(!inDeg[i]) q.push(i);
        
        //basic topSort
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            seen.insert(curr);
            for(auto& child : graph[curr]) {
                if(child == 2) cout << curr;
                inDeg[child]--;
                if(!inDeg[child]) q.push(child);
            }
        }
        
        
        return seen.size() == 61;
    }
    
    void search(vector<vector<int>>& graph, const vector<vector<int>>& targetGrid, vector<int>& inDeg, int color) {
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        //find bounds for outer region
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                if(targetGrid[i][j] == color) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        
        //color not found
        if(minX == INT_MAX) return;
        
        //check if theres any different colors inside the bounds
        for(int i = minX; i <= maxX; ++i)
            for(int j = minY; j <= maxY; ++j) {
                int interiorColor = targetGrid[i][j];
                //if a color appers in the interior of another color (think example 3), then both the exterior and interior color will ++ thier inDegs.
                //Thus they will never be added to the topSort q because there wouldn't be a source for those two nodes
                if(interiorColor != color) {
                    graph[interiorColor].push_back(color);
                    inDeg[color]++;
                }
            }
    }
};