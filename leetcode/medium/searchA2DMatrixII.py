class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix[0])
        
        for i in matrix:
            idx = bisect.bisect_left(i, target)
            if idx == n: continue
            if i[idx] == target:
                return True
        
        return False