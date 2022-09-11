class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        res, d = 0, defaultdict(int)
        for i in nums:
            if d[k-i]:
                d[k-i] -= 1
                res += 1
            else: d[i] += 1
        return res