class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        x, y = points[0]
        res = 0
        for xx, yy in points[1:]:
            diffX, diffY = abs(x-xx), abs(y-yy)
            if diffX <= diffY:
                res += (diffX + (diffY-diffX))
            else:
                res += (diffY + (diffX-diffY))
            x, y = xx, yy
        return res