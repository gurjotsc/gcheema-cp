class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        res = 0
        for k in range(2,len(nums)):
            needJ = nums[k]-diff
            needI = needJ-diff
            if needJ in nums[:k] and needI in nums[:k]: res += 1
        return res