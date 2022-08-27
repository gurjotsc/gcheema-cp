class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        return sum([nums[i] for i in range(0, n, 2)])