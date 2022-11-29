class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        if not n:
            return []
        res = []
        l, r = 0, 1
        while r < n:
            if nums[r] == nums[r-1]+1:
                r += 1
            else:
                res += [str(nums[l])] if l == r-1 else [str(nums[l]) + "->" + str(nums[r-1])]
                l = r
                r += 1
        return res + [str(nums[l])] if l == r-1 else res + [str(nums[l]) + "->" + str(nums[r-1])]