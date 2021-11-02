class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        matrix = []
        #create 0 matrix
        for i in range(m):
            row = [0] * n
            matrix.append(row)
        #iterate through indicies and increment appropriately
        for r, c in indices:
            for i in range(n):
                matrix[r][i] += 1
            for i in range(m):
                matrix[i][c] += 1
        #create an array of all 1's for each off value and sum it
        return sum([1 for i in range(m) for j in range(n) if matrix[i][j] % 2])

                
