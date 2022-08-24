class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        n = len(colors)
        l, r = 0, 1
        res = 0
        while r < n:
            if colors[l] == colors[r]:
                while r < n and colors[r] == colors[l]:
                    r += 1
                res += sum(neededTime[l:r]) - max(neededTime[l:r])
                l = r-1
            else:
                l = r
                r += 1
        return res