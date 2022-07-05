class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        m, n = len(board), len(board[0])
        r = 0
        c = 0
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'R':
                    r = i
                    c = j
        res = 0
        def check(i, j, x, y):
            ii = copy.deepcopy(i)
            jj = copy.deepcopy(j)
            while ii >= 0 and ii < m and jj >= 0 and jj < n:
                if board[ii][jj] == 'p':
                    return 1
                if board[ii][jj] == 'B':
                    return 0
                ii += x
                jj += y
            return 0
        res += check(r, c, 1, 0)
        res += check(r, c, -1, 0)
        res += check(r, c, 0, 1)
        res += check(r, c, 0, -1)
        return res
        
        
            