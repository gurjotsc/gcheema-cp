class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                //if the cell is a battle ship
                if(board[i][j] == 'X') {
                    //if the cell is the left most or top most cell in the battleship then increment res
                    //in other words, by checking if the cell to the left and above it are both '.' tehn we can increment res (the reason we use && is because no two ships are adjacent so if you have a vertical ship for example, then all the [i-1][j] cells are going to be '.' The same applies for the horizontal case) If the cell does have 'X' above or to the left, then we won't increment res to ensure res is only incremented once per battleship
                    if((i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.'))
                        ++res;
                }
            }
        }
        return res;
    }
};
