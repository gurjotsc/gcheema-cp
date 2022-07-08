class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        n, res = len(nums), 0
        for i in range(n):
            for j in range(i+1, n):
                res += ((nums[i]==nums[j]) and not ((i*j)%k))
        return res