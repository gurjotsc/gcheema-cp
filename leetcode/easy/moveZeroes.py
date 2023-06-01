class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if (0 not in nums):
            return
        n = len(nums)
        l = nums.index(0)
        r = l+1

        while(l < n and r < n):
            while(r < n and nums[r] == 0):
                r += 1
            if(r == n):
                break
            
            l = nums.index(0)
            nums[l], nums[r] = nums[r], nums[l]
            r = l+1