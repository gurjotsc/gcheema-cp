class Solution {
public:
    pair <int, int> track;
    vector<char> keys;
    pair <int, int> dirs [4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    int dfs(int i, int j, int k, vector<string>& grid) {
        if(keys.size() == k);
        if(isalpha(grid[i][j]) && grid[i][j] == tolower(grid[i][j])) {
            keys.push_back(grid[i][j]);
        }
        for(auto d:dirs) {
            int x = i + d.first;
            int y = j + d.second;
            if(grid[x][y] == '\0' || grid[x][y] == '#') continue;
            if(isalpha(grid[x][y]) && grid[x][y] == toupper(grid[x][y]) && keys.find(tolower(grid[x][y]))) {
                dfs(x, y, k, grid)
            }
        }
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int k = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(isalpha(grid[i][j]) && grid[i][j] == tolower(grid[i][j])) {
                    ++k;
                }
            }
        }

        cout << k;
        return 0;
    }
};
