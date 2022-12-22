import copy
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        b = copy.deepcopy(board)
        m, n = len(b), len(b[0])
        def check(board, i, j):
            dirs = [[0,1], [1,1], [1,0], [1,-1], [0,-1], [-1,-1], [-1,0], [-1,1]]
            cnt = 0
            for d in dirs:
                ii, jj = i+d[0], j+d[1]
                if ii < 0 or ii >= m or jj < 0 or jj >= n:
                    continue
                cnt += board[ii][jj]
            
            if board[i][j] == 0:
                return 1 if cnt == 3 else 0
            else:
                return 1 if cnt in (2,3) else 0


        for i in range(m):
            for j in range(n):
                b[i][j] = check(board, i, j)

        for i in range(m):
            board[i][:] = b[i][:]