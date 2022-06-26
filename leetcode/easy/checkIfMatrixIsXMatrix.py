class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if (i == j or j == (n-i-1)) and grid[i][j] == 0:
                    return False
                elif (i != j and j != (n-i-1)) and grid[i][j] != 0:
                    return False
        return True