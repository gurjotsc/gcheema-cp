class Solution:
    def countElements(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        sm, lg = nums[0], nums[n-1]
        res = 0
        for i in nums:
            res += (i > sm and i < lg)
        return res