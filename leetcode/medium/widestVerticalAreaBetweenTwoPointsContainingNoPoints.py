class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort()
        n = len(points)
        res = 0
        for i in range(0, n-1):
            res = max(res, points[i+1][0] - points[i][0])
        return res