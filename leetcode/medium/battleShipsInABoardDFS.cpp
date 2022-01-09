class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {0,1}};
    int m, n, res;
    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '.';
        for(auto d : dirs) {
            int x = i + d.first;
            int y = j + d.second;
            if(x >= m || y >= n) continue;
            if(board[x][y] == '.') continue;
            dfs(board, x, y);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'X') {
                    ++res;
                    dfs(board, i, j);
                }
            }
        }
        return res;
    }
};
