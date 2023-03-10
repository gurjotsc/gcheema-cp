class Solution {
public:
    int m, n;
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int x) {
        if(i < 0 || i == m || j < 0 || j == n) return false;
        if(board[i][j] != word[x]) return false;
        if(x == word.size()-1) return true;
        
        board[i][j] = ' ';
        bool res = (
            dfs(board, word, i+1, j, x+1) ||
            dfs(board, word, i, j+1, x+1) ||
            dfs(board, word, i-1, j, x+1) ||
            dfs(board, word, i, j-1, x+1)
        );
        board[i][j] = word[x];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(dfs(board, word, i, j, 0)) return true;
        return false;
    }
};