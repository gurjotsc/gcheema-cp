class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        n = len(nums)
        for i in nums:
            res += [(curr + [i]) for curr in res]
        return res