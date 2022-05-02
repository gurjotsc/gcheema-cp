class Solution {
public:
    int g = 1;
    int w = 2;
    int inView = 3;
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> graph(m, vector<int>(n));
        for(auto i : guards) graph[i[0]][i[1]] = g;
        for(auto i : walls) graph[i[0]][i[1]] = w;
        
        for(int i = 0; i < m; ++i) {
            bool seenG = false;
            //l to r
            for(int j = 0; j < n; ++j) {
                if(graph[i][j] == g) seenG = true;
                else if (graph[i][j] == w) seenG = false;
                else if(seenG) graph[i][j] = inView;
            }
            //r to l
            for(int j = n-1; j >= 0; --j) {
                if(graph[i][j] == g) seenG = true;
                else if (graph[i][j] == w) seenG = false;
                else if(seenG) graph[i][j] = inView;
            }
        }
        for(int j = 0; j < n; ++j) {
            bool seenG = false;
            //top to bottom
            for(int i = 0; i < m; ++i) {
                if(graph[i][j] == g) seenG = true;
                else if (graph[i][j] == w) seenG = false;
                else if(seenG) graph[i][j] = inView;
            }
            //bottom to top
            for(int i = m-1; i >= 0; --i) {
                if(graph[i][j] == g) seenG = true;
                else if (graph[i][j] == w) seenG = false;
                else if(seenG) graph[i][j] = inView;
            }
        }

        int res = 0;
        for(auto i : graph)
            for(auto j : i) res += (!j);
        return res;
            
    }
};