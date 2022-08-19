class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        return sum([mat[i][i] for i in range(len(mat))]) + sum([mat[j][len(mat)-j-1] for j in range(len(mat)-1,-1,-1)]) - sum([mat[len(mat)//2][len(mat)//2] if len(mat)%2 else 0])