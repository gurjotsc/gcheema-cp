class Solution:
    def findLHS(self, nums: List[int]) -> int:
        res = 0
        c = Counter(nums)
        for i in c:
            if(c[i+1]): res = max(res, c[i] + c[i+1])
        return res;