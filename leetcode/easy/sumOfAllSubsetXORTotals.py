class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        for mask in range(2**n):
            xor = 0
            for j in range(n):
                if mask & (1<<j):
                    xor ^= nums[n-j-1]
            res += xor
        return res