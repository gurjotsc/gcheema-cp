class Solution:
    def earliestFullBloom(self, pt: List[int], gt: List[int]) -> int:
        n, res = len(pt), 0
        l = sorted(zip(gt, pt), reverse = True)
        res = l[0][0] + l[0][1]
        prevGrowStart = l[0][1]

        for i in range(1,n):
            res = max(res, l[i][0]+l[i][1]+prevGrowStart)
            prevGrowStart = prevGrowStart+l[i][1]
        
        return res